#include <iostream>
#include <memory>
#include <cassert>
using namespace std;

struct Foo { 
  int x; 
  int test () { return x; }
};

unique_ptr<int> foo( unique_ptr<int> ptr ) {
  return ptr;
}

int main() {
  // A std::unique_ptr is a class template that manages the lifetime 
  // of a dynamically stored object.
  // Unlike for std::shared_ptr, the dynamic object is owned by only one 
  // instance of a std::unique_ptr at any time

  // int with value 59
  unique_ptr<int> ptr = make_unique<int>(59);
  // array of 15 ints
  unique_ptr<int[]> _ptr = make_unique<int[]>(15); // array specializations
  
  // You can access the std::unique_ptr just like a raw pointer, 
  // because it overloads those operators
  *ptr = 10; // Change value to 1

  // You can transfer ownership of the contents of a smart pointer 
  // to another pointer by using std::move, which will
  // cause the original smart pointer to point to nullptr.
  unique_ptr<int> ptr2 = move(ptr);
  ptr = foo( move(ptr2) ); // Passing unique_ptr to functions as parameter
  assert( 10 == *ptr );

  // The sharing behavior is implemented through a technique known as reference counting
  Foo foo; foo.x = 5;
  shared_ptr<Foo> p1 = make_shared <Foo> (foo);
  
  // Important: don't created more pointers with a reference to the same instance 
  // with the costructor because it will cause a double free error
  // shared_ptr<Foo> sh (&foo); // undefined behavior

  // instead use the alias constructor
  shared_ptr<int> p2( p1, &p1->x );
  // Both p2 and p1 own the object of type Foo, but p2 points to its int member x. 
  // This means that if p1 goes out of scope or is reassigned, the underlying Foo 
  // object will still be alive, ensuring that p2 does not dangle.

  // The smart pointer works just like a raw pointer.
  // This means, you can use * to dereference them.
  assert( p1->test() == 5); // The regular -> operator works as well
  
  // p2.reset();

  // By default, shared_ptr increments the reference count and doesn't transfer 
  // the ownership. However, it can be made to transfer the ownership using std::move
  shared_ptr<int> p3 = move(p2);
  
  // Sharing with temporary ownership (std::weak_ptr)

  return 0;
}
