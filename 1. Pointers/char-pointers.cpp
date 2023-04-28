#include <iostream>
using namespace std;

int main () {
	char str[] = "abcde";
	cout<<sizeof(str)<<endl;
	cout<<str[5]<<endl;
	char* pstr = "abcde";
	cout<<pstr<<endl;
	cout<<str<<endl;
	cout<<str[0]<<endl;
	cout<<pstr[0]<<endl;
	char a = 'a';
	char *pa = &a;
	cout<<a<<endl;
	cout<<pa<<endl;




	return 0;
	}

