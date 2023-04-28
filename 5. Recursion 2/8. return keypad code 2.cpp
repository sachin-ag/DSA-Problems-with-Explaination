#include <iostream>
#include <string>
using namespace std;

void helper(int num, string output) {
    if (num <= 1) {
        cout<<output<<endl;
        return;
    }
    string a[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int b = num%10;
    string c = a[b-2];
    helper(num/10, c[0] + output);
    helper(num/10, c[1] + output);
    helper(num/10, c[2] + output);
    if ((b==7)||(b==9)) {
        helper(num/10, c[3] + output);
    }
}

void printKeypad(int num){
    string output = "";
    helper(num, output);
}


int main(){
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}
