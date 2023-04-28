#include <iostream>
using namespace std;

int sum(int a[], int s) {
	int sum = 0;
	for (int i=0; i<s; i++)
	sum += a[i];
	return sum;
} 

int main () {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	cout<<sum(a, 10)<<endl;
	cout<<sum(a+3, 7);
	



	return 0;
	}

