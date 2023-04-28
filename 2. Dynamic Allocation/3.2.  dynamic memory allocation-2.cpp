#include <iostream>
using namespace std;

int main () {
	/*static memory (stack) is released automatically on end of scope
	dynamic memory (heap) requires manual release using 'delete'
	in the code:  while(true) {int* p = new int;}, again again new memory will be allocated on every loop so program
	will crash. Thus remember to delete a dynamically allocated memory. It is also independent of scope
	
	while(true) {
	int i = 10;} no problems
	
	while(true) {
	int* i = new int;} memory leakage as heap is not automaically released*/
	
	int* p = new int; //p created in stack as pointer stores address of an integer in heap of 4 bytes
	*p = 10; cout<<*p<<endl;
	delete p; //deletes the memory whose address is stored in p but not p itself
	cout<<*p; //garbage as the memory now is not ours
	
	p = new int[100]; //dynamic array
	delete [] p; //deleting full array
	return 0;
	}

