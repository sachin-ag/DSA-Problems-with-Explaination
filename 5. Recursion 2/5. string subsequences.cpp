#include <iostream>
using namespace std;

int subsequences(string input, string output[]) {
	if (input.empty()) {
		output[0] = "";
		return 1;
	}
	int smallOutput = subsequences(input.substr(1), output);
	for (int i=0; i<smallOutput; i++) {
		output[i + smallOutput] = input[0] + output[i]; //concatenation
	}
	return 2*smallOutput;
}

int main () {
	string a;
	cin>>a;
	string* output = new string[1000];
	int count = subsequences(a, output);
	cout<<count<<endl;
	for (int i=0; i<count; i++) {
		cout<<output[i]<<endl;
	}
	return 0;
	}

