#include <iostream>
#include <vector>
using namespace std;
// we will use HEAPS
// CBT (Complete Binary Tree) can be easily stored and worked on in an array.
// parent index = (cI-1)/2
// child indices = 2i+1, 2i+2

class PriorityQueue {
    vector<int> pq;

    public:

    PriorityQueue() {

    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if (this -> isEmpty()) {
            return 0; // priority queue is empty
        }
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        // up - heapify
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1)/2;
            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if (this -> isEmpty()) {
            return 0; // priority queue is empty
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        // down - heapify
        int parentIndex = 0;
        int child1 = parentIndex*2 + 1, child2 = child1 + 1;
        while (true) {
            if (child1 > pq.size() - 1) {
                break;
            } else if (child2 > pq.size() - 1) {
                child2 = child1;
            }
            int minIndex; // stores the index of minimum of parent and children
            int minimum = min(pq[parentIndex], min(pq[child1], pq[child2]));
            if (minimum == pq[parentIndex]) {
                break;
            } else if (minimum == pq[child1]) {
                minIndex = child1;
            } else {
                minIndex = child2;
            }
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;
            parentIndex = minIndex;
            child1 = parentIndex*2 + 1;
            child2 = child1 + 1;
        }
        return ans;
    }

};

int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
    return 0;
}