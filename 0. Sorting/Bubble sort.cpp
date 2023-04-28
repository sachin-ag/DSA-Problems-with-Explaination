#include <iostream>
using namespace std;

//swap function
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//print function
void print(int a[], int n) {
	for (int i=0; i<n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

//typical buble sort
void bubblesort1(int a[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<n-1; j++) {
			if(a[j]>a[j+1]) {
				swap(a[j], a[j+1]);
			} else continue;
		}
	}
}

//time-sensitive buble sort
void bubblesort2(int a[], int n) {
	for (int i=0; i<n-1; i++) {
		int y = 0;
		for (int j=0; j<n-i-1; j++) { //"n-i-1" because the largest unsorted element goes to last position after each pass
			if(a[j]>a[j+1]) {
				swap(a[j], a[j+1]);
				y = 1;
			} else continue;
		}
		if (y == 0) break; //if there is no change in one whole pass then array is sorted
	}
}

int main () {
	const int size = 7;
	int a[size];
	for (int i=0; i<size; i++) {
		cin>>a[i];
	}
	print(a, size);
	bubblesort2(a, size);
	print(a, size);
	
	
	
	return 0;
	}

