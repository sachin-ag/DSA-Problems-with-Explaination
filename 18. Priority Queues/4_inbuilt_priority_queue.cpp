#include <iostream>
using namespace std;
#include <queue>
// inbuilt priority queue is a max pq

int main() {
    priority_queue<int> pq;

    pq.push(98); // inserts elements in the pq
    pq.push(55);
    pq.push(45);
    pq.push(67);
    pq.push(32);
    pq.push(5);

    cout << "Size: " << pq.size() << endl;
    cout << "Top: " << pq.top() << endl;

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop(); // pops the top most (maximum) element
    }

    return 0;
}