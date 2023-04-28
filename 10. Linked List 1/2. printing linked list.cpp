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
	Node *temp = head; // so that we dont lose head for further use in head
	while(temp != NULL) {
		cout << temp -> data <<" ";
		temp = temp -> next; // address shifted to next node
	}
	cout<<endl;
}

int main () {
	//statically
	
	Node n1(1);
	Node *head = &n1;
	
	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);
	
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	
	print(head);
	print(head);
	
		
	//dynamically
	
	Node *m1 = new Node(10);
	Node *m2 = new Node(20);
	
	Node *head2 = m1; //// first node address is now in head pointer
	m1 -> next = m2; //as m2 is a pointer pointing to a node class object
	
	print(head2);
	
	return 0;
	}

