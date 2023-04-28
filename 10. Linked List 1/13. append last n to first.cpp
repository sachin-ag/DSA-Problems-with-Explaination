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

Node *appendLastNToFirst(Node *head, int n) {
	if (head == NULL) {
        return head;
    }
    Node *temp = head;
    Node *temp2 = head;
    int i = 0, l = 0;
    while (temp -> next != NULL) {
        temp = temp -> next;
        l++;
    }
    while (i < l - n) {
        temp2 = temp2 -> next;
        i++;
    }
    temp -> next = head;
    Node *a = temp2 -> next;
    temp2 -> next = NULL;
    return a;
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
	Node *head = takeinput();
	int n;
	cin >> n;
	head = appendLastNToFirst(head, n);
	print(head);
	return 0;
}
