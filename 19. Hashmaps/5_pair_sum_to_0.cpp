#include <iostream>
using namespace std;
#include <unordered_map>

int pairSum(int *arr, int n) {
    int ans = 0;
    unordered_map<int, int> map;
    for (int i=0; i<n; i++) {
        if (map[-1 * arr[i]] > 0) {
            ans += map[-1 * arr[i]];
        }
        map[arr[i]]++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}