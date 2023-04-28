#include <iostream>
using namespace std;
// You are given with an array of integers and an integer K. 
// You have to find and print the count of all such pairs which have difference K.
// Note: Take absolute difference between the elements of the array.
#include <unordered_map>

int getPairsWithDifferenceK(int *arr, int n, int k) {
    unordered_map<int, int> temp;
    for (int i=0; i<n; i++) {
        if (temp.count(arr[i]) == 0) {
            pair<int, int> p;
            p.first = arr[i];
            p.second = 1;
            temp.insert(p);
        } else {
            temp[arr[i]] += 1;
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        
        if (temp[arr[i]] == 0) {
            continue;
        }
        temp[arr[i]] -= 1;
        int a = arr[i] - k;
        if (a < 0) {
            a *= -1;
        }
        if (temp.count(a) == 0) {
            continue;
        }
        ans += temp[a];
        
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}