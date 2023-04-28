#include <iostream>
using namespace std;

void printsubs(string input, string output) {
	if (input.empty()) {
		cout<<output<<endl;
		return;
	}
	printsubs(input.substr(1), output); //decision: first char is not included
	printsubs(input.substr(1), output + input[0]); //decision: first char is included
}

int main () {
	string a;
	cin>>a;
	string b = "";
	printsubs(a, b);
	cout<<b;
	return 0;
	}

