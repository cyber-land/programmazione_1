#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

bool _func(const int& element) { return (element > 3); }
void fun(int const& value) { cout << value << " "; }

struct Point { double x, y; Point(double x, double y) : x(x), y(y) {} };

int main () {

  /* initializing */ {
  vector<int> v1{ 3, 6 }; // becomes {3, 6}
  vector<int> v2(3, 6);   // becomes {6, 6, 6}
  vector<int> v3(4);      // becomes {0, 0, 0, 0}
  vector<int> v4(v1);         // copies data
  vector<int> v5 = move(v1);  // moves  data
  // iterator (range) copy-construction, which copies elements
  vector<int> v6(v2.begin(), v2.begin() + 3);
  int z[] = { 1, 2, 3, 4 };
  vector<int> v7(z, z+3); // becomes {1, 2, 3}
  // using the assign() function a vector can be reinitialized after its construction
  v1.assign(4, 100);      // becomes {100, 100, 100, 100}
  }

  /* index-based access */ {
  vector<int> v{ 1, 2, 3 };
  // Because the at() method performs bounds checking and can throw exceptions, it is slower than []
  int a = v[1]; // a is 2
  v.at(2) = 5;  // v now contains { 1, 3, 5 }
  // Note: It is undefined behavior to invoke front() or back() on an empty vector
  int b = v.front();
  v.back() = 7;
  }


  /* deleting */ {
  vector<int> v{ 1, 2, 3, 4, 5, 6 };
  v.pop_back(); // deleting the last element
  v.erase(v.begin() + 2); // deleting element by index
  v.clear();     // deleting all elements
  v = { 1, 2, 3, 4, 5, 6 };
  // This is a relatively inefficient operation for any indices less than the last index
  // because all elements after the erased segments must be relocated to new positions
  v.erase(v.begin() + 1, v.begin() + 5); // deleting all elements in a range
  v = { 1, 1, 2, 2, 3, 3 };
  int value_to_remove = 2;
  v.erase( remove(v.begin(), v.end(), value_to_remove), v.end() ); // deleting elements by value
  // deleting elements by condition ( using lambda, without creating additional function )
  v.erase( remove_if(v.begin(), v.end(), _func), v.end() );
  v.erase( remove_if(v.begin(), v.end(), [](auto& element){return element > 3;} ), v.end() );
  }

  /* iterating */ {
  vector<int> vec{ 1, 2, 3 };
  auto it = vec.begin(); // is possible doing point arithmetic on this
  for(const auto& value: vec) cout << value << " "; cout << endl;
  for_each( begin(vec), end(vec), fun ); cout << endl;
  for_each( rbegin(vec), rend(vec), [](auto const& value) { cout << value << " "; } ); cout << endl;
  }

  // vector<bool>: The Exception To So Many, So Many Rules
  // molto diverso da tutti gli altri tipi, quindi da usare solo se strettamente necessario
  vector<char> trad_vect =      {true, false, false, false, true, false, true, true};
  vector<bool> optimized_vect = {true, false, false, false, true, false, true, true};
  // Bitwise representation: [1,0,0,0,1,0,1,1]

  /* inserting elements */ {
  vector<Point> v;
  v.push_back(Point(10.0, 2.0));  // p is copied into the vector
  v.emplace_back(10.0, 2.0);      // The object is constructed in the vector, avoiding a copy
  // Note that vector does not have a push_front() member function due to performance reasons
  v.insert(v.begin(), Point(9.9, 8.8));         // Inserting an element at any position
  v.emplace(v.begin()+1, Point(6.0, 4.4));      // constructing an element at any position
  vector<Point> v2(2, Point(10,11));
  v.insert(v.begin()+2, v2.begin(), v2.end());  // Inserting another vector at any position
  // for(const auto& value: v) cout << value.x << "/" << value.y << " "; cout << endl;
  }

  /* finding an element */ {
  vector<int> v = {1,2,3,4,5};
  auto /*vector<int>::iterator*/ it = find(v.begin(), v.end(), 2); // 'it' points to the second element
  auto /*vector<int>::difference_type*/ index = distance(v.begin(), it); // return 1

  // binary search
  sort(v.begin(), v.end());
  it = lower_bound(v.begin(), v.end(), 42);
  if (it != v.end() && *it == 42) { } // we found the element!

  // Note: If the requested value is not part of the vector, lower_bound() will return an
  // iterator to the first element that is greater than the requested value.
  // This behavior allows us to insert a new element at its right place in an already sorted vector
  int const new_element = 33;
  v.insert( lower_bound(v.begin(), v.end(), new_element ), new_element );

  bool exists = binary_search(v.begin(), v.end(), 42);
  }

  /* concatenating */ {
  vector<int> a = {0, 1, 2, 3, 4};
  vector<int> b = {5, 6, 7, 8, 9};
  a.insert( a.end(), b.begin(), b.end() );
  // this is a more general solution, for example, because b can also be an array
  a.insert( end(a), begin(b), end(b) );
  // those solutions don't allow you to append a vector to itself
  }

  /* matices */ {
  vector< vector<int> > matrix(3, vector<int>(4)); // 3 rows and 4 columns with each cell initialised as 0
  int var = matrix[0][2]; // access
  for(auto& row: matrix) for(auto& col : row) {} //cout << col << endl;
  // represent a matrix like that it's not the most efficient way
  }

  /* Vector size and capacity */ {
  vector<int> v = { 1, 2, 3 }; // size is 3
  const vector<int>::size_type size = v.size(); // size is not necessarily (or even usually) int
  cout << size << endl << boolalpha << v.empty() << endl;
  vector<int> v1; // size is 0
  // adding/removing N elements to vector increases/decreases size by N
  // size is simply how many elements the vector currently has
  // capacity is for how many elements it allocated/reserved memory for
  const vector<int>::size_type capacity = v.capacity();
  v.reserve(1000); // now capacity is 1000
  v.shrink_to_fit(); // You can request for the excess capacity to be released
  // vector usually do not automatically shrink
  }

  /*  Iterator/Pointer Invalidation */ {
  vector<int> v = { 1, 2, 3 };
  // vector::reserve will allocate the memory but will not resize your vector,
  // which will have a logical size the same as it was before.
  // vector::resize will actually modify the size of your vector and will fill any space
  // with objects in their default state. If they are ints, they will all be zero.

  // Any insertion operation which changes the capacity of the vector will invalidate all iterators/pointers
  vector<int> v(5); // Vector has a size of 5; capacity is unknown.
  int *p1 = &v[0];
  v.push_back(2); // p1 may have been invalidated, since the capacity was unknown.
  v.reserve(20);  // Capacity is now at least 20.
  int *p2 = &v[0];
  v.push_back(4); // p2 is *not* invalidated, since the size of `v` is now 7.
  v.insert(v.end(), 30, 9); // Inserts 30 elements at the end. The size exceeds the
                            // requested capacity of 20, so `p2` is (probably) invalidated.
  int *p3 = &v[0];
  v.reserve(v.capacity() + 20); // Capacity exceeded, thus `p3` is invalid.

  int* p = v.data();  // returns a pointer to the raw memory used by v
  int c = p[2];       // using vector as a c-array
  v.resize(42);       // internal memory location changed; value of p is now invalid
  auto old_cap = v.capacity();
  v.shrink_to_fit();
  if(old_cap != v.capacity()) { /* Iterators were invalidated */ }

  // Any insertion operation, which does not increase the capacity, will still invalidate iterators/pointers
  // pointing to elements at the insertion position and past it. This includes the end iterator
  vector<int> v(5);
  v.reserve(20);    // Capacity is at least 20.
  int *p1 = &v[0];
  int *p2 = &v[3];
  v.insert(v.begin() + 2, 5, 0);  // p2 is invalidated, but since the capacity did not change, p1 remains valid
  int *p3 = &v[v.size() - 1];
  v.push_back(10);  // The capacity did not change, so `p3` and `p1` remain valid.

  // Any removal operation will invalidate iterators/pointers pointing to the removed elements and to any
  // elements past the removed elements. This includes the end iterator
  vector<int> v(10);
  int *p1 = &v[0];
  int *p2 = &v[5];
  v.erase(v.begin() + 3, v.end()); // p2 is invalid, but p1 remains valid

  // operator = (copy, move, or otherwise) and clear() will invalidate all iterators/pointers pointing
  }

  /* Find max and min Element and Respective Index in a Vector */ {
  vector<int> v = {5, 2, 8, 10, 9};
  int maxElementIndex =  max_element(v.begin(), v.end()) - v.begin();
  int maxElement      = *max_element(v.begin(), v.end());
  int minElementIndex =  min_element(v.begin(), v.end()) - v.begin();
  int minElement      = *min_element(v.begin(), v.end());
  // min and max can be retrieved at the same time
  auto minmax = minmax_element(v.begin(), v.end());
  cout << "minimum element: " << *minmax.first << endl;
  cout << "maximum element: " << *minmax.second << endl;
  }

  return 0;
}
