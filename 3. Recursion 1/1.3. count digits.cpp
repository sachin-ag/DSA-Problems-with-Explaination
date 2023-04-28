#include <iostream>
using namespace std;
int count(int n) {
	if (n/10 == 0)
	return 1;
	else
	return count(n/10) + 1;
}

int main () {
	int n;
	cin>>n;
	cout<<endl<<count(n);
	return 0;
	}

