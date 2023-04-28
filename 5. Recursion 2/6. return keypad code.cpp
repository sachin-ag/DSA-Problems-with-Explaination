#include <iostream>
using namespace std;
/*Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and 
	return the count of elements populated in the output array. */
	
#include <string>
using namespace std;

int keypad(int num, string output[]) {
    if (num <= 1) {
        output[0] = "";
        return 1;
    }
    int temp = keypad(num/10, output);
    int n = num%10;
    char a, b, c, d;
    if (n == 2) {
        a = 'a', b = 'b', c = 'c';
    }
    if (n == 3) {
        a = 'd', b = 'e', c = 'f';
    }
    if (n == 4) {
    	a = 'g', b = 'h', c = 'i';
    }
    if (n == 5) {
		a = 'j', b = 'k', c = 'l';
    }
    if (n == 6) {
        a = 'm', b = 'n', c = 'o';
    }
    if (n == 7) {
        a = 'p', b = 'q', c = 'r', d = 's';
    }
    if (n == 8) {
        a = 't', b = 'u', c = 'v';
    }
    if (n == 9) {
        a = 'w', b = 'x', c = 'y', d = 'z';
    }
    for (int i=0; i<temp; i++) {
        if((n==7)||(n==9)) {
            output[i + 3* temp] = output[i] + d;
        }
        output[i + 2* temp] = output[i] + c;
        output[i + temp] = output[i] + b;
        output[i] = output[i] + a;
    }
    if((n==7)||(n==9)) {
        return 4*temp;
    } else {
        return 3*temp;
    }
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    cout<<count<<endl;
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

