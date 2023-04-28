#include <iostream>
using namespace std;

int main () {
	//int* p = new int[n]; is wrong
	//Steps:
	//1.Create a dynamic array of pointers pointing to each row in the 2d array
	int** p = new int*[10]; // this array can stores 10 pointers in dynamic memory
	//2. individual rows
	for (int i=0; i<10; i++)
	p[i]=new int[20]; //each row has 20 elements and there are 10 rows so array of 10X20
	
	//one can also create a 2d array with diff no of elements in each row
	//to access the elements use p[4][5];
	
	//to delete 2d array:
	for (int i=0; i<10; i++)
	{delete [] p[i];}
	delete [] p;

	return 0;
	}

