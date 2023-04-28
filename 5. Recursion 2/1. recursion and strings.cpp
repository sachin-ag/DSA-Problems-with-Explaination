#include <iostream>
using namespace std;

int length(char s[]) {
	if (s[0] == '\0') {
		return 0;
	}
	return 1 + length(s+1);
}

void removex(char s[]) {
	if (s[0] != '\0') {
		if (s[0] == 'x') {
			for (int i=0; s[i] != '\0'; i++) {
				s[i] = s[i+1];
			}
			removex(s);
		} else {
			removex(s+1);
		}
	}
}

int main () {
	char s[100];
	cin>>s;
	cout<<endl<<length(s)<<endl;
	removex(s);
	cout<<s<<endl<<length(s)<<endl;
	return 0;
	}

