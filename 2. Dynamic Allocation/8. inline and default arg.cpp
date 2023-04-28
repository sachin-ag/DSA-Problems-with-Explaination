#include <iostream>
using namespace std;

// default arguments are '=0' placed after a and b
// important: only right most elemtents can be given default values (any no. of right most args)
inline int max(int a = 0, int b = 0) { //inline simply copies the fn code everywhere it is called to reduce perf. hit from coping of var.
	return (a>b) ? a:b; //tertiary operator
} //inline works only on small functions

int main () {
	int a, b;
	cin>>a>>b;
	int c=max(a,b);
	
	int x, y;
	x=12;
	y=34;
	int z=max(x,y);
	
	return 0;
	}

