#include <iostream>
using namespace std;
/* A child runs up a staircase with 'n' steps and 
can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count and return all possible ways 
in which the child can run-up to the stairs. */

long staircase(int n) {
    long* ans = new long[n+1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for (int i=3; i<=n; i++) {
        long x, y, z;
        x = ans[i-1];
        y = ans[i-2];
        z = ans[i-3];
        ans[i] = x + y + z;
    }
    return ans[n];
}

int main() {
	int n;
	cin >> n;
	cout << staircase(n);
}