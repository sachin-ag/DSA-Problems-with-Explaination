#include <iostream>
#include <string.h>
using namespace std;

void replacePi(char input[]) {
    int size = strlen(input);
    if (size > 1) {
        if ((input[0]=='p')&&(input[1]=='i')) {
            for (int i=0; i<size -1; i++) {
                input[size + 2 - i] = input[size -i];
            }
            input[0] = '3';
            input[1] = '.';
            input[2] = '1';
            input[3] = '4';
            replacePi(input+4);
        }
        else {
            replacePi(input + 1);
        }
    }
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

