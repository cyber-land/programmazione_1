#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

/*
std::map and std::multimap both keep their elements sorted according to the ascending order of keys. In
case of std::multimap, no sorting occurs for the values of the same key.

The basic difference between std::map and std::multimap is that the std::map one does not allow duplicate
values for the same key where std::multimap does.

Maps are implemented as binary search trees. So search(), insert(), erase() takes Θ(log n) time in
average. For constant time operation use std::unordered_map.

size() and empty() functions have Θ(1) time complexity, number of nodes is cached to avoid walking
through tree each time these functions are called.
*/

int main() {

  /* initializing */
  map < int, string > mp {
    make_pair(2, "stackoverflow"),
    make_pair(1, "docs-beta"),
    make_pair(3, "stackexchange")
  };
  // From map or multimap iterator
  multimap< int , int > mmp { {1, 2}, {3, 4}, {6, 5}, {8, 9}, {6, 8}, {3, 4}, {6, 7} };
  auto iterator = mmp.begin();
  advance(iterator,3); //moved cursor on first {6, 5}
  map< int, int > _mp (iterator, mmp.end()); // {6, 5}, {8, 9}
  //From vector of pair
  vector< pair<int, int> > v { {1, 5}, {5, 1}, {3, 6}, {3, 2} };
  unordered_map< int, int > ump (v.begin(), v.end());

  bool empty = mp.empty();
  auto elements = mp.size();

  /* accessing elements */
  string a = mp[2];
  // will throw an out_of_range exception if the container does not contain the requested element
  string b = mp.at(1);
  auto it2 = mp.begin();
  cout << it2->first << " : " << it2->second << endl; // Output: "1 : docs-beta"
  it2++;
  cout << it2->first << " : " << it2->second << endl; // Output: "2 : stackoverflow"

  /* inserting elements */ {
  map< string, size_t > fruits_count;
  fruits_count.insert(make_pair("orange", 30));
  auto success = fruits_count.insert({"grapes", 20});
  // The insert() function returns a pair consisting of an iterator and a bool value:
  // If the insertion was successful, the iterator points to the newly inserted element, and the bool value is true
  // If there was already an element with the same key, the insertion fails.
  // When that happens, the iterator points to the element causing the conflict, and the bool is value is false
  if (!success.second) { // we already have 'grapes' in the map
    success.first->second += 20; // access the iterator to update the value
  }
  fruits_count["apple"] = 10; // insert new ones if they don't exist
  // can be used to add several elements at once using a braced list of pairs.
  // This version of insert() returns void
  fruits_count.insert({{"apricot", 1}, {"jackfruit", 1}, {"lime", 1}, {"mango", 7}});
  // can also be used to add elements by using iterators denoting the begin and end of value_type values:
  map< string, size_t > fruit_list{ {"lemon", 0}, {"olive", 0}, {"plum", 0}};
  fruits_count.insert(fruit_list.begin(), fruit_list.end());
  // Time complexity for an insertion operation is O(log n) because map are implemented as trees
  }

  // searching
  auto it = mmp.find(6);
  if(it!=mmp.end()) cout << it->first << ", " << it->second << endl; //prints: 6, 5
  // counts how many values are associated with a given key
  int values = mp.count(3); // for maps can only return 0 or 1
  // in case of multimap, to get this range, the equal_range() function is used which returns
  // std::pair having iterator lower bound (inclusive) and upper bound (exclusive) respectively
  auto eqr = mmp.equal_range(6);
  auto st = eqr.first, en = eqr.second;
  for(auto it = st; it != en; ++it)
    cout << it->first << ", " << it->second << endl;

  /* type of maps
  Regular Map
  A map is an associative container, containing key-value pairs.
  The key acts as an index in the map. Each key must be unique, and must be ordered.

  Multi-Map
  Multimap allows multiple key-value pairs with the same key to be stored in the map.
  Otherwise, its interface and creation is very similar to the regular map.

  Hash-Map (Unordered Map)
  A hash map stores key-value pairs similar to a regular map.
  It does not order the elements with respect to the key though.
  Instead, a hash value for the key is used to quickly access the needed key-value pairs.
  Unordered maps are usually faster, but the elements are not stored in any predictable order.
  For example, iterating over all elements in an unordered_map gives the elements in a seemingly random order. */

  /* deleting */ {
  multimap< int , int > mmp{ {1, 2}, {3, 4}, {6, 5}, {8, 9}, {3, 4}, {6, 7} };
  auto it = mmp.begin();
  advance(it,3);
  mmp.erase(it); // remove the third element
  mmp.erase(6); // Removing all elements having a provided value as key
  mmp.erase(mmp.begin(),--mmp.end()); // Removing all elements in a range
  mmp.clear(); // removing all elements
  }

  // iterating
  for(const auto &x: mmp) cout<< x.first <<":"<< x.second << " , "; cout << endl;
  for (auto it = mmp.rbegin(); it != mmp.rend(); ++it)
    cout<< it->first <<":"<< it->second << " , "; cout << endl;

  /* Creating std::map with user-defined types as key
  If your value type does not specify any ordering,
  or you want to override the default ordering, you may provide one: */
  struct StrLess {
    bool operator()(const std::string& a, const std::string& b) {
    return strncmp(a.c_str(), b.c_str(), 8)<0; //compare only up to 8 first characters
    }
  };
  // Strict Weak Ordering
  map< string, size_t, StrLess > fruits_count2;

  return 0;
}
