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

Node *skipMdeleteN(Node *head, int M, int N) {
    if (head == NULL) {
        return head;
    }
    if (M == 0) {
        return NULL;
    }
    if (N == 0) {
        return head;
    }
    int c1 = 1, c2 = 1;
    Node* temp1 = NULL;
    Node* temp2 = NULL;
    temp1 = head;
    while (c1 != M) {
        if (temp1 -> next == NULL) {
            break;
        }
        temp1 = temp1 -> next;
        c1++;
    }
    if (temp1 -> next == NULL) {
        return head;
    }
    temp2 = temp1 -> next;
    while (c2 != N) {
        if (temp2 -> next == NULL) {
            break;
        }
        temp2 = temp2 -> next;
        c2++;
    }
    temp2 = temp2 -> next;
    if (temp2 == NULL) {
        temp1 -> next = NULL;
    } else {
        temp1 -> next = temp2;
        temp1 -> next = skipMdeleteN(temp1 -> next, M, N);
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
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
