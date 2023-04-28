#include <iostream>
using namespace std;

int main () {
	int i = 55;
	int *p = &i;
	int **q = &p;
	cout<<**q<<endl;
	int *r = *q;
	(*r)++;
	cout<<i;




	return 0;
	}

