#include <iostream>
#include <string.h>
using namespace std;

bool helper(char input[], int start, int end) {
    if (start >= end) {
		return true;
	}
    else {
    	if (helper(input, start + 1, end - 1)) {
    		if (input[start] == input[end])
    			return true;
    		else
    			return false;
		}
	}
}

bool checkPalindrome(char input[]) {
	return helper(input, 0, strlen(input) - 1);
}

int main () {
	char a[] = "abcba";
	cout<<checkPalindrome(a)<<endl;
	cout<<sizeof(a)<<endl<<strlen(a) + 1;
	return 0;
}

