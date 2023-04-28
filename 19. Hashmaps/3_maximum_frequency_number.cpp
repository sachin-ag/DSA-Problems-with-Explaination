#include <iostream>
using namespace std;
#include <unordered_map>

int highestFrequency(int arr[], int n) {
    unordered_map<int, int> map;
    for (int i=0; i<n; i++) {
    	map[arr[i]]++;
    }
    int max_freq_num = arr[0];
    for (int i=0; i<n; i++) {
        if (map[max_freq_num] < map[arr[i]]) {
            max_freq_num = arr[i];
        }
    }
    return max_freq_num;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}