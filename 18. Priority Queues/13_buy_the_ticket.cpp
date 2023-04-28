// 5 2 3 2 2 4 3
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    priority_queue<int> pq;
    int time = 0;
    for (int i=0; i<n; i++) {
        pq.push(arr[i]);
    }
    int i = 0;
    while (arr[k] != -1) {
        if (i == n) {
            i = 0;
        }
        if (arr[i] != -1) {
            if (arr[i] >= pq.top()) {
                pq.pop();
                time += 1;
                arr[i] = -1;
                i++;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    return time;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}