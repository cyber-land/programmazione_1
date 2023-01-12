# Referencing and dereferencing operators

**Referencing** means taking the address of an existing variable (using &) to set a pointer variable. In order to be valid, a pointer has to be set to the address of a variable of the same type as the pointer, without the asterisk:

**Dereferencing** a pointer means using the * operator (asterisk character) to retrieve the value from the memory address that is pointed by the pointer:
NOTE: The value stored at the address of the pointer must be a value OF THE SAME TYPE as the type of variable the pointer "points" to, but there is **no guarantee** this is the case unless the pointer was set correctly. The type of variable the pointer points to is the type less the outermost asterisk.

A **pointer** is a variable which stores the address of another variable.
Pointers are said to "point to" the variable whose address they store.
 
```cpp
int a = 5;
int *b = &a; // reference/inderection: store the memory address of 'a'
cout << "a has address: " << &a << " and value: " << a << endl;
cout << "b has address: " << &b << " and value: " << b << endl;
// dereferencing 'b' ( the pointer to 'a' ) return the value of 'a'
cout << "and point to " << *b << endl;
```

compile to something like
```
a has address: 0x7ffe3819a384 and value: 5  
b has address: 0x7ffe3819a378 and value: 0x7ffe3819a384  
and point to 5
```

# Dynamic memory management
slides: 9.1

**Stack**
Allocating data into the `stack` is very fast compared to `heap` allocation, as all the memory has already been assigned for this purpose.
Data stored on the stack is only valid so long as the scope that allocated the variable is still active.

**Heap**
Areas of memory allocated from the `heap` may live longer than the original scope in which it was allocated.
When using `new` and `delete` instead `malloc` and `free`, the constructor and destructor will get executed (Similar to stack based objects).

```cpp
struct type { int v1, v2; };
// storing on the stack
{
    int a = 0;
    type b = { 6, 7 };
    cout << &b << " " << b.v1 << endl;
} // end lifetime of 'a' and 'b'

// storing on the heap
int* c = new int; // allocation
char* d;
{ 
    char* e = new char[] {'a', 'b', 'c'};
    d = e;
} // end lifetime of 'e' but the memory is never freed so 'd' is still valid
delete c; // deallocation
cout << d << endl; // print 'abc'
delete [] d; // now the memory is finally released
type *f = new type { 8, 9 };
// f (a pointer) store the reference to a memory address in the heap
cout << &f << " " << f << " " << f->v1 << endl;
```

compile to something like
```
0x7fffd46514d0 6
abc
0x7fffd46514b8 0x55bfcc7612e0 8
```
si noti che `b` ed `e` sono vicini in memoria mentre l'indirizzo nello heap è molto distante

# Smart pointers

# Iterators

# Standard library
see local files

## Files

```cpp
#include <fstream>
#include <string>
using namespace std;
int main() {
    
	ifstream ifs;
	ifs.open("./input.txt"); // reading only
	if (!ifs.is_open()) return 1;
	string name; int age;
	while (ifs >> name >> age) { }
	ifs.close();
    
	ofstream os("output.txt"); // writing only
	if(!os.is_open()) return 1;
	os << name << " " << age << endl;
	if (os.bad()) return 1; //Failed to write
	os.close();
    
    return 0;
}
```

- String
- Vector
    https://www.geeksforgeeks.org/vector-in-cpp-stl/
    
    Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. 
    Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. 
    In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes the array may need to be extended. 
    Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.
- Map

# Random

```cpp
#include <iostream>
#include <stdlib.h>
using namespace std;
// generate random integers in a range [ Min , Max )
int random_int(int min, int max) {
  if ( min >  max ) return random_int(max, min);
  if ( min == max ) return min;
  return min + (rand() % (max - min));
}
float random_float() {
  return (float)(rand()) / (float)(rand());
  // generate the fraction part only
  // return (float)(rand()) / (float)(RAND_MAX);
}
int main() {
  srand(time(0));
  for(int i = 1; i <= 5; i++) {
    int number = rand() % 100; // [ 0, 100 )
    cout << number  << " " << random_float() << " " << random_int(10, 20) << endl;
  }
  return 0;
}
```
