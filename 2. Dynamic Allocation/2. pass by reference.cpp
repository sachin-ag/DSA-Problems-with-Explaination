#include <iostream>
using namespace std;

//variable is deleted after fn ends so garbage will be returned
int& f1(int n) {
	int a=n;
	return a;
} //returning reference of a

int* f2(int n) {
	int a=10;
	return &a;
} //returning pointer to a

int main () {
	int i=10;
	int& j = i;
	j++;
	cout<<i<<endl;
	int& k1 = f1(j);
	int* k2 = f2(i);
	cout<<k1<<endl;
	cout<<*k2<<endl;
	// garbage returned as a is deleted in both the cases



	return 0;
	}

