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

Node* deleteNode(Node *head, int i) {
	Node *temp = head;
	if (i == 0) {
		Node *a = head -> next;
		delete head;
		head = a;
		return head;
	}
	int count = 0;
	while (temp != NULL && count < i-1) {
		temp = temp -> next;
		count++;
	}
    if (temp == NULL || temp -> next == NULL) {
        return head;
    }
	Node *temp2 = temp -> next;
	Node *a = temp2 -> next;
	delete temp -> next;
	temp -> next = a;
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
	int i;
	cin>>i;
	head = deleteNode(head, i);
	print(head);
	return 0;
	}

