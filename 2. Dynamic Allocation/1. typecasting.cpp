#include <iostream>
using namespace std;

int main () {
	char pc[] = "ABCD";
	int *p = (int*)pc;
	cout<<pc<<endl;
	cout<<&pc<<endl;
	
	cout<<p<<endl;
	cout<<*p<<endl;
	cout<<int(*pc)<<endl;
	cout<<int(*(pc+1))<<endl;
	cout<<int(*(pc+2))<<endl;
	cout<<int(*(pc+3))<<endl;
	
	int i =65;
	int *q = &i;
	char *ch = (char*)q;
	cout<<*q<<endl;
	cout<<*ch<<endl;
	cout<<*(ch+1)<<endl;
	
	return 0;
	}

