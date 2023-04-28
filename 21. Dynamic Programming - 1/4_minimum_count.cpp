#include <bits/stdc++.h>
using namespace std;
/* Given an integer N, find and return the count of 
minimum numbers required to represent N as a sum of squares.

That is, if N is 4, then we can represent it as : 
            {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
The output will be 1, as 1 is the minimum count of numbers 
required to represent N as sum of squares. */

// brute force approach
int minCountBrute(int n) {
	if (n <= 1) {
		return n;
	}
	int a = 1, b = 1;
	int ans = INT_MAX;
	while (b <= n) {
		int temp = 1 + minCountBrute(n - b);
		if (temp < ans) ans = temp;
		a++;
		b = a*a;
	}
	return ans;
}

// memoization approach
int minCountHelp(int n, int* ans) {
	if (n <= 1) {
		return n;
	}
	if (ans[n] == -1) {
		int a = 1, b = 1;
		int c = INT_MAX;
		while (b <= n) {
			int temp = 1 + minCountHelp(n - b, ans);
			if (temp < c) c = temp;
			a++;
			b = a*a;
		}
		ans[n] = c;
	}
	return ans[n];
}
int minCountMemo(int n) {
	int* ans = new int[n+1];
	for (int i=0; i<=n; i++) {
		ans[i] = -1;
	}
	return minCountHelp(n, ans);
}

// dynamic programming approach
int minCountDP(int n) {
	int* ans = new int[n+1];
	for (int i=0; i<=n; i++) {
		ans[i] = -1;
	}
	ans[0] = 0;
	ans[1] = 1;
	for (int i=2; i<=n; i++) {
		int a = 1, b = 1;
		int c = INT_MAX;
		while (b <= i) {
			int temp = ans[i - b] + 1;
			if (temp < c) c = temp;
			a++;
			b = a*a;
		}
		ans[i] = c;
	}
	
	return ans[n];
}

int main() {
	int n;
	cin >> n;
	cout << minCountBrute(n) << endl; // takes a lot of time
	cout << minCountMemo(n) << endl;
	cout << minCountDP(n) << endl;
}