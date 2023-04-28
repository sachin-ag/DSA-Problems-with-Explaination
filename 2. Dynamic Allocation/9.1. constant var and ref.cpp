#include <iostream>
using namespace std;

int main () {
	int const i1 = 10; //constant variable
	const int i2 = 12; //both are same
	//int const i; is illegal
	
	//const reference to non-const var
	int j = 15;
	const int &k = j; //read-only path shared to k by j
	j++; //allowed as j can both read and write
	// k++; is not allowed because k has only read-only path
	
	//const ref to const variable
	const int j2 = 14; //j2 is read-only var
	//IMPORTANT: non-const ref to const var not allowed!!! as j2 has only read only access so k2 cannot write either
	const int &k2 = j2; //as j2 itself is read-only, it can only share read only path with k2
	//so both j2++ and k2++ are not allowed as both are read only paths
	
	return 0;
	}

