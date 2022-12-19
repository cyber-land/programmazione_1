#include <iostream>
#include <string>

using namespace std;

int main() {
	/*
	int a = 5;
	int *b = &a; // store the memory address of 'a'
	cout << "a has address: " << &a << " and value: " << a << endl;
	cout << "b has address: " << &b << " and value: " << b << endl;
	// dereferencing 'b' the pointer to 'a' return the value of 'a'
	cout << "that point to " << *b << endl; */

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
	cout << &f << " " << f << endl;
	cout << f->v1 << endl;

	return 0;
}

