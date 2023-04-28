#include <iostream>
#include <string>
using namespace std;
#include <stack>

/* For a given expression in the form of a string, 
find if there exist any redundant brackets or not. 
It is given that the expression contains only rounded brackets or 
parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression 
is surrounded by unnecessary or needless brackets.
*/

#include <stack>
bool checkRedundantBrackets(string expression) {
	int size = expression.size();
	stack<int> s;
	int i = 0;
	while (i < size) {
		if (expression[i] =='('||expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/') {
			s.push(expression[i]);
		} else if(expression[i]==')'){
			int count = 0;
			while (s.top() != '(') {
				count += 1;
				s.pop();
			}
			s.pop();
			if (count == 0) {
				return true;
			}
		}
		i++;
	}
	return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}
