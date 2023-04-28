#include <bits/stdc++.h>
using namespace std;
/* An integer matrix of size (M x N) has been given. 
Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes. */

// 1. brute force approach
int minCostHelper(int **input, int m, int n, int i, int j) {
    if ((i == m - 1) && (j == n - 1)) {
		return input[m-1][n-1];
	}
	int a = INT_MAX, b = INT_MAX, c = INT_MAX;
	if (i < m - 1) a = minCostHelper(input, m, n, i + 1, j);
	if (j < n - 1) b = minCostHelper(input, m, n, i, j + 1);
	if ((i < m - 1) && (j < n - 1)) c = minCostHelper(input, m, n, i + 1, j + 1);
	return min(a, min(b, c)) + input[i][j];
}
int minCostPath(int **input, int m, int n) {
    return minCostHelper(input, m, n, 0, 0);
}

// 2. memoization approach
int minCostHelper(int** input, int m, int n, int i, int j, int** ans) {
	if (i == m-1 && j == n-1) {
		return input[i][j];
	}
	if (ans[i][j] != -1) {
		return ans[i][j];
	}
	int a = INT_MAX, b = INT_MAX, c = INT_MAX;
	if (i < m - 1) a = minCostHelper(input, m, n, i + 1, j, ans);
	if (j < n - 1) b = minCostHelper(input, m, n, i, j + 1, ans);
	if ((i < m - 1) && (j < n - 1)) c = minCostHelper(input, m, n, i + 1, j + 1, ans);
	ans[i][j] = min(a, min(b, c)) + input[i][j];
	return ans[i][j];
}
int minCostPathMemo(int **input, int m, int n) {
	int** ans = new int*[m];
	for (int i=0; i<=m; i++) {
		ans[i] = new int[n];
	}
	for (int i=0; i<=m; i++) {
		for (int j=0; j<=n; j++) {
			ans[i][j] = -1;
		}
	}
	return minCostHelper(input, m, n, 0, 0, ans);
}

// 3. dynamic programming
int minCostPathDP(int **input, int m, int n) {
	int** ans = new int*[m+1];
	for (int i=0; i<=m; i++) {
		ans[i] = new int[n+1];
	}
	ans[m-1][n-1] = input[m-1][n-1];
	for (int i=m-1; i>=0; i--) {
		for (int j=n-1; j>=0; j--) {
			if (j == n-1 && i == m-1) continue;
			int a = INT_MAX, b = INT_MAX, c = INT_MAX;
			if (i < m - 1) a = ans[i+1][j];
			if (j < n - 1) b = ans[i][j+1];
			if ((i < m - 1) && (j < n - 1)) c = ans[i+1][j+1];
			ans[i][j] = input[i][j] + min(a, min(b, c));
		}
	}
	return ans[0][0];
}

int main() {
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
	cout << minCostPathMemo(arr, n, m) << endl;
	cout << minCostPathDP(arr, n, m) << endl;
}