#include <iostream>
using namespace std;

int main () {
	const int size = 7;
	int a[size];
	for (int i=0; i<size; i++) {
		cin>>a[i];
	}
	for (int i=0; i<size; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	for (int i=0; i<size; i++) {
		int temp = a[i];
		int temp2 = a[i];
		int b = i;
		for (int j=i; j<size; j++) {
			if (temp>a[j]) {
				temp = a[j];
				b = j;
			} else continue;
		}
		a[i] = a[b];
		a[b] = temp2;
	}
	
	for (int i=0; i<size; i++) {
		cout<<a[i]<<" ";
	}
	
	return 0;
	}

