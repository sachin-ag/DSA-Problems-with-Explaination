#include <iostream>
using namespace std;
#include <string.h>

/* Suppose you have a string, S, made up of only 'a's and 'b's. 
Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false. */

bool checkAB(char input[]);

bool helper(char input[]) {
	if (input[0] == '\0') {
        return true;
    }
    if (input[0] == 'a') {
        return helper(input + 1);
    } else if ((input[0] = 'b') && (input[1] == 'b')) {
        if (input[2] == '\0') {
            return true;
        } else {
            return checkAB(input + 2);
        }
    } else {
        return false;
    }
}

bool checkAB(char input[]) {
	if (strlen(input) == 0) {
        return false;
    }
    if (input[0] != 'a') {
        return false;
    }
   return helper(input + 1);  
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}

