#include <iostream>
#include <string.h>
using namespace std;

void removeX(char input[]) {
    int size = strlen(input);
    if (size > 0) {
        if (input[0] == 'x') {
            for (int i=0; i<size; i++) {
                input[i] = input[i+1];
            }
            removeX(input);
        }
        else {
            removeX(input + 1);
        }
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

