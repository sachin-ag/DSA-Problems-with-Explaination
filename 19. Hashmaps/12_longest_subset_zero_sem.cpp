#include <iostream>
using namespace std;
// Given an array consisting of positive and negative integers, 
// find the length of the longest subarray whose sum is zero.
#include <unordered_map>

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> temp;
    unordered_map<int, int> sumIndex;
    int ans = 0;
    pair<int, int> p;
    p.first = 0;
    p.second = arr[0];
    sumIndex .insert(p);
    for (int i=1; i<n; i++) {
        pair<int, int> p;
        p.first = i;
        p.second = sumIndex[i-1] + arr[i];
        
    }
    for (int i=0; i<n; i++) {
        int sum = sumIndex[i];
        if (temp.count(sum) == 0) {
            pair<int, int> p;
            p.first = sum; // sum till i elements
            p.second = i;
            temp.insert(p);
        } else {
            // sum alaready exists means bw elements are zero
            int a = i = temp[sum];
            if (a > ans) {
                ans = a;
            }
        }
    }
    return ans;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}