#include <iostream>

// method 1 : reverse whole LL then compare (make sure to make a copy of original LL)
// method 2 : find midpoint and reverse half of LL (done here)
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

Node* midpoint_linkedlist(Node *head)
{
    Node *slow = head;
    Node *fast = head -> next;
    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* reverse_linked_list_rec(Node *head)
{
    if (head == NULL || head -> next == NULL) {
        return head;
    }
	Node *ans = reverse_linked_list_rec(head -> next);
    Node *temp = head -> next; //as head is still pointing to 2nd node which is last node of returned LL
    temp -> next = head;
    head -> next = NULL;
    return ans;
}

bool isPalindrome(Node *head) {
    if (head == NULL || head -> next == NULL) {
        return true;
    }
    Node *mid = midpoint_linkedlist(head);
    mid = reverse_linked_list_rec(mid);
    while (head != NULL && mid != NULL) {
        if (head -> data != mid -> data) {
            return false;
        }
        head = head -> next;
        mid = mid -> next;
    }
    return true;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}
