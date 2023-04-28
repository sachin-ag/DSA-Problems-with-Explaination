#include <iostream>
using namespace std;
bool checkNumber(int input[], int size, int x) {
	if (size == 0)
    	return false;
    if (input[0] == x)
        return true;
    else
        return checkNumber(input + 1, size - 1, x);
}

int main () {
	return 0;
	}

