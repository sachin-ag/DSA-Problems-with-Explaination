#include <iostream>
using namespace std;

// brute force method
int fibo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}


// following approach is called memoization, it is top down approach
int fibo_help(int n, int* ans) {
    if (n <= 1) {
        return n;
    }
    // check if output already exists
    if (ans[n] != -1) {
        return ans[n];
    } else {
        int a = fibo_help(n-1, ans);
        int b = fibo_help(n-2, ans);
        ans[n] = a + b; // for use in recursive calls
        return a + b;
    }
}
int fibo_1(int n) {
    int* ans = new int[n+1];
    for (int i=0; i<=n; i++) {
        ans[i] = -1;
    }
    return fibo_help(n, ans);
}

// DYNAMIC PROGRAMMING:- ( it is a bottom up approach)
int fibo_2(int n) {
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i=2; i<=n; i++) {
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    cout << fibo_1(n) << endl;
    cout << fibo_2(n) << endl;
    return 0;
}