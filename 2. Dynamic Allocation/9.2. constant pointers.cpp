#include <iostream>
using namespace std;

void fn1 (int const &a) {//val of arg is now un changeable
	
}

void fn2 (const int *p) { //this ensures that fn will not change the val of arg
	
}

int main () {
	int const i = 10;
	int j = 11;
	
	// int *p = &i; not allowed as *p has write access which cannot be given by a const int
	
	int const *p = &i; //p is a pointer to a const var
	p=&j; //allowed as p is not const in itself but the place it was ref to was const
	
	int *const p2 = &j; //value of pointer p is now unchangeable but *p and j are not const
	*p2 = 20;
	//p2=&i; these things are not allowed with p2
	
	int const * const p3 = &i; //both p3 and *p3 are consts now
	
	int k = 10; // both read and write permission to j
	int const *p4= &k; //only read access given to p2
	k++; // *p2++; not allowed
	
	fn1(*p4);
	fn2(&k);

	return 0;
	}

