#include <bits/stdc++.h>

#include <climits>
using namespace std;
/* Given a positive integer 'n', find and return the minimum 
number of steps that 'n' has to take to get reduced to 1. 
You can perform any one of the following 3 steps:

1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).     */

// brute force method
int countMinStepsToOne(int n) {
    if (n == 1) {
        return 0;
    }
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
    if (n%3 == 0) {
        min1 = countMinStepsToOne(n/3);
    }
    if (n%2 == 0) {
        min2 = countMinStepsToOne(n/2);
    }
    min3 = countMinStepsToOne(n - 1);
    int ans = min(min1, min(min2, min3));
    return 1 + ans;
}
// memoization
int countMinStepsHelp(int n, int* ans) {
    if (n == 1) {
        return 0;
    }
    if (ans[n] != -1) {
        return ans[n];
    } else {
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
        if (n%3 == 0) {
            min1 = countMinStepsHelp(n/3, ans);
        }
        if (n%2 == 0) {
            min2 = countMinStepsHelp(n/2, ans);
        }
        min3 = countMinStepsHelp(n - 1, ans);
        ans[n] = 1 + min(min1, min(min2, min3));
        return ans[n];
    }
}
int countMinStepsMemo(int n) {
    int *ans = new int[n+1];
    for (int i=0; i<=n; i++) {
        ans[i] = -1;
    }
    return countMinStepsHelp(n, ans);
}

//dynamicprogramming
int minStepsTo1DP(int n) {
    int *ans = new int[n+1];
    ans[1] = 0;
    for (int i=2; i<=n; i++) {
        int x = INT_MAX, y = INT_MAX, z = INT_MAX;
        x = ans[i-1];
        if (i%2 == 0) y = ans[i/2];
        if (i%3 == 0) z = ans[i/3];
        ans[i] = min(x, min(y, z));
    }
    return 1 + ans[n];
}

int main() {
	int n;
	cin >> n;
	cout << countMinStepsToOne(n) << endl;
    cout << countMinStepsMemo(n) << endl;
    cout << minStepsTo1DP(n) << endl;
    return 0;
}