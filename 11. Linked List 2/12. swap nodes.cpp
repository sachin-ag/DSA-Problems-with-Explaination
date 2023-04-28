#include <iostream>

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

using namespace std;

Node *swapNodes(Node *head, int i, int j) {
    int a = 1, b = 1;
    Node* temp1 = NULL;
    Node* temp2 = NULL;
    temp1 = head;
    temp2 = head;
    while (a < i) {
        temp1 = temp1 -> next;
        a++;
    }
    while (b < j) {
        temp2 = temp2 -> next;
    	b++;
    }
    int temp = temp1 -> next -> data;
    temp1 -> next -> data = temp2 -> next -> data;
    temp2 -> next -> data = temp;
    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
