#include <iostream>
using namespace std;

int main () {
	int a = 5;
	int * p = &a;
	cout<<*p<<endl;
	cout<<p<<endl;
	cout<<p+1<<endl;
	int b[25];
	for (int i=0; i<25; i++)
	b[i] = i*i;
	cout<<sizeof(p)<<endl;
	cout<<sizeof(b)<<endl;
	cout<<*(b+7)<<endl;
	cout<<b<<endl;
	cout<<&b<<endl;


	return 0;
	}

