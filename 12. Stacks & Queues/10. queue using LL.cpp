#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
	
	Node *head;
	Node *tail;
	int size;
	
	public:
		
		Queue () {
			head = NULL;
			tail = NULL;
			size = 0;
		}
		
		int getSize() {
			return size;
		}
		
		bool isEmpty() {
			return size == 0;
		}
		
		void enqueue(int data) {
			Node *newNode = new Node(data);
			if (head == NULL) {
				head = newNode;
				tail = newNode;
				size++;
			} else {
				tail -> next = newNode;
				tail = tail -> next;
				size++;
			}
		}
		
		int dequeue() {
			if (head == NULL) {
				return -1;
			}
			Node *temp = head -> next;
            int ans = head -> data;
			delete head;
			head = temp;
			size--;
			return ans;
		}
		
		int front() {
			if (head == NULL) {
				return -1;
			}
			return head -> data;
		}
		
};


int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
