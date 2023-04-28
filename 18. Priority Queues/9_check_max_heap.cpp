#include <iostream>
using namespace std;
#include <queue>

bool isMaxHeap(int arr[], int n) {
    if (n == 0 || n == 1) {
        return true;
    }
    if (n == 2) {
        if (arr[0] > arr[1]) {
            return true;
        } else {
            return false;
        }
    }
    queue<int> pendingElements;
    pendingElements.push(0);
    while (!pendingElements.empty()) {
        int parentIndex = pendingElements.front();
        pendingElements.pop();
        int child1 = 2 * parentIndex + 1;
        int child2 = 2 * parentIndex + 2;
        if (child1 >= n) {
            break;
        } else if ((child1 < n) && (child2 >= n)) {
            child2 = child1;
        }
        if ((arr[parentIndex] > arr[child1]) && arr[parentIndex] > arr[child2]) {
            pendingElements.push(child1);
            pendingElements.push(child2);
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}