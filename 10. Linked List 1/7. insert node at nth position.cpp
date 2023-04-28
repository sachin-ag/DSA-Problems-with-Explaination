#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node* insertNode(Node *head, int i, int data) {
	Node *temp = head;
	Node *newnode = new Node(data);
	if (i == 0) {
		newnode -> next = head;
		head = newnode;
		return head;
	}
	int count = 0;
	while (temp != NULL && count < i-1) {
		temp = temp -> next;
		count++;
	}
	if (temp != NULL) {
		newnode -> next = temp -> next;
		temp -> next = newnode;
	}
	return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head) {
	Node *temp = head;
	while(temp != NULL) {
		cout << temp -> data <<" ";
		temp = temp -> next;
	}
	cout<<endl;
}


int main () {
	Node *head = takeinput();
	print(head);
	int i, data;
	cin>>i>>data;
	head = insertNode(head, i, data);
	print(head);
	return 0;
	}

