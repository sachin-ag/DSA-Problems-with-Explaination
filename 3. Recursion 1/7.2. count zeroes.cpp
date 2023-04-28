#include <iostream>
using namespace std;


int countZeros(int n) {
	if (n == 0)
        return 0;
	int temp = countZeros(n/10);
    if (n%10 == 0)
        return temp + 1;
    else
        return temp;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
