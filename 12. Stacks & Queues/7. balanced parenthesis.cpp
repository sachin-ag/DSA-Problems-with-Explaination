#include <iostream>
#include <string>
using namespace std;
/*For a given a string expression containing only round brackets or parentheses, 
check if they are balanced or not. 
Brackets are said to be balanced if the bracket which opens last, closes first.
*/

#include <stack>
bool isBalanced(string expression) {
    stack<char> s;
    int size = expression.size();
    int i = 0;
    while(i<size) {
        if (expression[i] == '(') {
            s.push('(');
        } else if (expression[i] == ')') {
        	if (s.empty()) {
                return false;
            }
            s.pop();
        }
        i++;
    }
    return s.empty();
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}

