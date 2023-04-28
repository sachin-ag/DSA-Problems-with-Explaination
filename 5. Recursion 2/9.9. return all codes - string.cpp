#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int stringtonum(string a) {
	int n = a.size();
    int c = 0;
    for (int i=0; i<n; i++) {
    	c = c + (a[i]-'0')*pow(10, n - i -1);
	}
	return c;
}

int getCodes(string input, string output[]) {
    if (input.size() == 0) {
        return 0;
    }
    if (input.size() == 1) {
        output[0] = input[0] + 48;
        return 1;
    }
    string output1[10000], output2[10000]; 
    int a = getCodes(input.substr(1) , output1);
    for (int i=0; i<a; i++) {
        output[i] = output1[i];
    }
    int b = 0;
    if (stringtonum(input.substr(0,2)) <= 26) {
        b = getCodes(input.substr(2), output2);
        char c = stringtonum(input.substr(0,2)) + 64;
        for (int i=a; i<a+b; i++) {
            output[i] = c + output2[i - a];
        }
    }
    return a + b;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

