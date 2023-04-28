#include <iostream>
using namespace std;
#include <queue>
// CODE FOR DECREASING ORDER

void KSortedArray(int input[], int n, int k) {
    priority_queue<int> pq;
    for (int i=0; i<k; i++) {
        pq.push(input[i]);
    }
    int j = 0; // element of imput we are working on
    for (int i=k; i<n; i++) {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while (!pq.empty()) {
        input[j] = pq.top();
        pq.pop();
        j++;
    }

}

int main() {
    int input[] = {10, 12, 6, 7, 9};
    KSortedArray(input, 5, 3);
    for (int i=0; i<5; i++) {
        cout << input[i] << " ";
    }
    return 0;
}