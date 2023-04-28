#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// Given a string S, you need to remove all the duplicates. 
// That means, the output string should contain each character only once. 
// The respective order of characters should remain same, as in the input string.

string uniqueChar(string str) {
    int length = str.length();
    string ans;
    unordered_map<char, int> temp;
    for (int i=0; i<length; i++) {
        if (temp.count(str[i]) > 0) {
            continue;
        } else {
            ans += str[i];
            pair<char, int> temp2;
            temp2.first = str[i];
            temp2.second = 1;
            temp.insert(temp2);
        }
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}