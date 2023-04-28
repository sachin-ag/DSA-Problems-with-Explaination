#include <iostream>
using namespace std;
#include <vector>

#include <vector>
#include <climits>
class PriorityQueue {
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex]) {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax() {
        if (this -> isEmpty()) {
            return INT_MIN; // priority queue is empty
        }
        return pq[0];
    }

    int removeMax() {
        if (this -> isEmpty()) {
            return INT_MIN; // priority queue is empty
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int leftChild = 2*parentIndex + 1;
        int rightChild = 2*parentIndex + 2;
        while (leftChild < pq.size()) {
            int maxIndex = parentIndex;
            if (pq[maxIndex] < pq[leftChild]) {
                maxIndex = leftChild;
            }
            if (rightChild < pq.size()) {
                if (pq[maxIndex] < pq[rightChild]) {
                    maxIndex = rightChild;
                }
            }
            if (maxIndex == parentIndex) {
                break;
            }
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[maxIndex];
            pq[maxIndex] = temp;
            parentIndex = maxIndex;
            leftChild = 2*parentIndex + 1;
        	rightChild = 2*parentIndex + 2;
        }
        return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
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
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
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
}