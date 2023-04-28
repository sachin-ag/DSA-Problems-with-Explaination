#include <iostream>
using namespace std;

bool splitArray(int *input, int size) {
    if (size <= 1) {
        return false;
    }
    if (size == 2) {
        if (input[0] != input[1]) {
            return false;
        } else if (input[0]%5 == 0) {
            return false;
        } else if (input[0]%3 == 0) {
            return false;
        } else {
            return true;
        }
    }
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
	return 0;
}
