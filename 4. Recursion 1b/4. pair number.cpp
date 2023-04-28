#include <iostream>
#include <string.h>
using namespace std;

void pairStar(char input[]) {
    int size = strlen(input);
    if (size > 1) {
        if (input[0] == input[1]) {
            for (int i=0; i<size; i++) {
                input[size + 1 - i] = input[size - i];
            }
            input[1] = '*';
            pairStar(input + 2);
        }
        else {
            pairStar(input + 1);
        }
    }
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

