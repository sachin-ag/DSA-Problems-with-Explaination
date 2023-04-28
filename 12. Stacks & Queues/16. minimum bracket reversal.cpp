#include <iostream>
#include <string>
using namespace std;
#include <stack>

/* For a given expression in the form of a string, 
find the minimum number of brackets that can be 
reversed in order to make the expression balanced. 
The expression will only contain curly brackets.
If the expression can't be balanced, return -1. */

int countBracketReversals(string input) {
	if (input.size() % 2 != 0) {
        return -1;
    }
    stack<int> s;
    for (int i=0; i<input.size(); i++) {
        if (input[i] == '{') {
            s.push(input[i]);
        } else if (input[i] == '}') {
            if (s.empty()) {
                s.push(input[i]);
            } else {
                if (s.top() == '{') {
                    s.pop();
                } else {
                    s.push(input[i]);
                }
            }
        }
    }
    int count = 0;
    while (!s.empty()) {
        char c1, c2;
        c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();
        if (c1 == c2) {
            count += 1;
        } else {
            count += 2;
        }
    }
    return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
