#include <iostream>
using namespace std;

//1. replace character
void replaceCharacter(char input[], char c1, char c2) {
    if (input[0] == '\0') {
        return;
    } else {
        if (input[0] == c1) {
            input[0] = c2;
            replaceCharacter(input+1, c1, c2);
        } else {
            replaceCharacter(input+1, c1, c2);
        }
    }
}

//2. remove consecutive duplicates
void removeConsecutiveDuplicates(char *input) {
	if ((input[0] == '\0') || (input[1] == '\0')) {
        return;
    } else {
        if (input[1] == input[0]) {
            for (int i=0; input[i] != '\0'; i++) {
                input[i] = input [i+1];
            }
            removeConsecutiveDuplicates(input);
        } else {
            removeConsecutiveDuplicates(input + 1);
        }
    }
}

int main () {
	return 0;
	}

