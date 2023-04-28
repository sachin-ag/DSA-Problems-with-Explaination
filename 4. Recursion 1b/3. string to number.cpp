#include <iostream>
using namespace std;
#include <string.h>
#include <cmath>

int stringToNumber(char input[]) {
    int size = strlen(input);
    if (size <= 0) {
        return 0;
    }
    int temp = stringToNumber(input + 1);
    int b = input[0] - '0';
    int c = pow(10, size-1);
    return b*c + temp;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

