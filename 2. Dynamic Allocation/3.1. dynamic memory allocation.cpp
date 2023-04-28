#include <iostream>
using namespace std;

int main () {
	int n;
	cin>>n;
	int a[n]; //should not do this, does not work every time.
	for (int i=0; i<n; i++)
	{a[i]=(i+1)*(i+1);
	cout<<a[i]<<endl;
	}
	cout<<endl<<endl;
	
	//"new int" creates a int memory in HEAP and and returns its address which should be stored in a pointer
	int* p = new int; //ponter p created in stack but variable is in the heap whose address is in pointer p
	*p=10; 
	cout<<*p<<endl;
	double* pd = new double;
	char* pc = new char;
	
	int* pa = new int[50]; //1.returns address of first element of array 2.memory allocated: 8byte of stack, 200 on heap 
	int m;
	cout<<"\nEnter number of elements: ";
	cin>>m;
	int* pa2 = new int[m]; //perfectly fine as array is created in heap during run time
	for (int i=0; i<m; i++)
	cin>>pa2[i]; //remember a[i]=*(a+i) always, in any case
	int max = -1000;
	for (int i=0; i<m; i++) {
		if (pa2[i]>max)
		max=pa2[i];
	}
	cout<<endl<<"Max of the numbers is "<<max;

	return 0;
	}

