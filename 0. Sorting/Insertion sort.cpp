#include <iostream>
using namespace std;
//https://www.youtube.com/watch?v=i-SKeOcBwko&t=8s

//print function
void print(int a[], int n) {
	for (int i=0; i<n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

//insertion sort
void insertionsort(int a[], int n) {
	for (int i=1; i<n; i++) {
		int value = a[i];
		int hole = i;
		while((hole>0)&&(a[hole-1]>value)) {
			a[hole] = a[hole-1];
			hole -= 1;
		}
		a[hole] = value;
	}
}

int main () {
	const int size = 7;
	int a[size];
	for (int i=0; i<size; i++) {
		cin>>a[i];
	}
	print(a, size);
	insertionsort(a, size);
	print(a, size);
	return 0;
	}

