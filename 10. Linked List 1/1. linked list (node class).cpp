#include <iostream>
using namespace std;

class Node {
	
	public:
		
		int data;
		Node *next; // contains address of next node
		
		Node (int data) {
			this -> data = data;
			next = NULL; // as there is only 1 element right now
		}
		
};

int main () {
	//no. of elements in linked list = no. of objects of class node
	
	//FIRST NODE IS CALLED "HEAD"
	//LAST NODE IS CALLED "TAIL"
	
	//statically (dynamically in next file)
	Node n1(1);
	
	Node n2(2);
	
	n1.next = &n2; // now n1 and n2 form a linked list
	
	//cout<<n1.data<<" "<<n2.data<<endl;
	
	Node *head = &n1; // first node address is now in head pointer
	
	cout << head -> data << " " << head -> next -> data << endl;
	
	return 0;
	}

