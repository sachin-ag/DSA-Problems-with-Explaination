#include <iostream>
using namespace std;

class Node {
	
	public:
		
		int data;
		Node *next;
		
		Node (int data) {
			this -> data = data;
			next = NULL;
		}
		
};

void print(Node *head) {
	Node *temp = head;
	while(temp != NULL) {
		cout << temp -> data <<" ";
		temp = temp -> next;
	}
	cout<<endl;
}

// time complexity is n^2 here, see next file for O(n)
Node* takeInput() { // using -1 as terminator
	int data;
	cin>>data;
	Node *head = NULL;
	
	while(data != -1) {
		Node *n = new Node(data); // scope of this pointer n is only till the loop but actual Node is in heap
		
		if (head == NULL) { // so that heap always point to just the first node
			head = n;
		} else {
			Node *temp = head;
			while(temp -> next != NULL) {
				temp = temp -> next;
			}
			temp -> next = n;
		}
		
		cin>>data;
	}
	
	return head;
}

int main () {
	Node *head;
	head = takeInput();
	print(head);
	return 0;
	}

