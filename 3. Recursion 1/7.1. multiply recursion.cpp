#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
	if (n == 0)
        return 0;
    if (n == 1)
        return m;
    int temp = multiplyNumbers(m, n-1);
    return temp + m;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}

