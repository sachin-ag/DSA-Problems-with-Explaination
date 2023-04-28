#include <iostream>
using namespace std;
#include <queue>
#include <vector>

// (nlogn complexity)
#include <queue>
void printRunningMedian(int *arr, int n) {
    priority_queue<int> max_pq; // for left half 
    priority_queue<int, vector<int>, greater<int>> min_pq; // for right half
    for (int i=0; i<n; i++) {
        int median = 0;
        if (max_pq.size() == 0) {
            max_pq.push(arr[i]);
        } else {
            if (arr[i] >= max_pq.top()) {
            	min_pq.push(arr[i]);
        	} else {
            	max_pq.push(arr[i]);
        	}
        }
        int size_diff = max_pq.size() - min_pq.size();
        if (size_diff > 1) {
            min_pq.push(max_pq.top());
            max_pq.pop();
            size_diff = max_pq.size() - min_pq.size();
        }
        if (size_diff < -1) {
            max_pq.push(min_pq.top());
            min_pq.pop();
            size_diff = max_pq.size() - min_pq.size();
        }
        if (i % 2 == 0) { // odd no of elements
            if (size_diff == 1) {
                median = max_pq.top();
            } else {
                median = min_pq.top();
            }
        } else { // even no of elements
            median = (max_pq.top() + min_pq.top())/2;
        }
        cout << median << " ";
    }
}

/* (n^2*logn complexity)
void printRunningMedian(int *arr, int n) {
    for (int i=0; i<n; i++) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> sorted_array;
        for (int j=0; j<=i; j++) {
            pq.push(arr[j]);
        }
        for (int j=0; j<=i; j++) {
            sorted_array.push_back(pq.top());
            pq.pop();
        }
        if (i % 2 == 0) {
            cout << sorted_array[i/2] << " ";
        } else {
            int temp = (sorted_array[i/2] + sorted_array[(i/2) + 1])/2;
            cout << temp << " ";
        }
    }
} */

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    printRunningMedian(arr, n);

    delete[] arr;
}