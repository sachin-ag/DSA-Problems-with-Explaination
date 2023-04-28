#include <iostream>
using namespace std;
int sum(int input[], int n) {
	if (n == 0) {
    	return 0;}
    if (n == 1) {
        return input[0];
    }
    else
	return input[n-1] + sum(input, n-1);
}


int main () {
	return 0;
	}

