#include <iostream>
using namespace std;
/* Given an integer h, find the possible number of balanced binary 
trees of height h. You just need to return the count of possible 
binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7. */

// brute force approach
int balancedBTs(int n) {
    if (n <= 1) {
        return 1;
    }
    int mod = 1e9 + 7; // 10^9 + 7
    long long int a = balancedBTs(n - 1);
    long long int b = balancedBTs(n - 2);
    long long int temp1 = (2* (long long int) a*b) % mod;
    long long int temp2 = ((long long int) a*a) % mod;
    long long int ans = (temp1 + temp2) % mod;
    return ans;
}
/* Explaination:-
In a balanced binary tree, both left and right subtree can have a
difference of 1 in height. So if height of left child is (n-1) then 
height of right can be (n-1) or (n-2) and vice versa. So we use this 
condititon to find out the answer recursively. */

// dynamic programming
int balancedBTsDP(int n) {
    long long int* ans = new long long int[n+1];
    ans[0] = 1;
    ans[1] = 1;
    for (int i=2; i<=n; i++) {
        int mod = 1e9 + 7; // 10^9 + 7
        long long int a = ans[i-1];
        long long int b = ans[i-2];
        long long int temp1 = (2* (long long int) a*b) % mod;
        long long int temp2 = ((long long int) a*a) % mod;
        ans[i] = (temp1 + temp2) % mod;
    }
    return ans[n];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}