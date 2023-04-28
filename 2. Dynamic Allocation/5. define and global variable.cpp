#include <iostream>
using namespace std;
#define pi 3.14 //memory is not allocated for 'pi' but it is replaced with 3.14 everywhere during compilation
#define multiply1(a,b) a*b //has problems (see below)
#define multiply2(a,b) (a)*(b) //always use this
#define square(x) x*x //important,see below

int a; //global variable
//beware here a can be changed by ANY FUNCTION ANYWHERE so it is risky so use pass by reference instead of global var.

void f() {
	a++;
	cout<<a<<endl;
}
void g() {
	cout<<a<<endl;
	a++;
	f();
}
int main () {
	a=10;
	f();
	g();
	cout<<a<<endl<<endl;
	
	cout<<multiply1(2+3,3+5)<<endl;
	cout<<multiply2(2+3,3+5)<<endl; //remember the difference
	
	int x;
	x = 36/square(6);
	cout<<endl<<x;
	/* what happened here is that square(6) = 6*6 so..
	36/square(6) = 36/6*6 = 6*6 = 36
	remember, define jus copy and paste and do no evaluation in itself. */
	
	return 0;
	}

