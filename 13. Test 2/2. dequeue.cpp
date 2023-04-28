#include<iostream>
using namespace std;
/* You need to implement a class for Dequeue i.e. for double ended queue. 
In this queue, elements can be inserted and deleted from both the ends.
You don't need to double the capacity. */

class Deque {
    int *data;
    int size;
    int capacity;
    int lastIndex;
    
    
    public:
    	Deque (int size) {
            data = new int[size];
            this -> size = 0;
            capacity = size;
            lastIndex = 0;
        }
    	void insertFront(int element) {
            if (size == capacity) {
                cout<<-1<<endl;
                return;
            } else if (size == 0) {
                data[0] = element;
                lastIndex = 0;
                size++;
            } else {
                for (int i=size; i>0; i--) {
                    data[i] = data[i-1];
                }
                data[0] = element;
                lastIndex += 1;
                size++;
            }
            
        }
    	void insertRear(int element) {
            if (size == capacity) {
                cout<<-1<<endl;
                return;
            } else if (size == 0) {
                data[0] = element;
                lastIndex = 0;
                size++;
            } else {
                data[lastIndex+1] = element;
                lastIndex += 1;
                size++;
            }
        }
    	void deleteFront() {
            if (size == 0) {
                cout<<-1<<endl;
                return;
            }
            for (int i=0; i<lastIndex; i++) {
                data[i] = data[i+1];
            }
            lastIndex--;
            size--;
        }
  	  void deleteRear() {
            if (size == 0) {
                cout<<-1<<endl;
                return;
            }
            lastIndex--;
            size--;
        }
    	int getFront() {
            if (size == 0) {
                return -1;
            }
            return data[0];
        }
    int getRear() {
        if (size == 0) {
            return -1;
        }
        return data[lastIndex];
    }
    	
};

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}
