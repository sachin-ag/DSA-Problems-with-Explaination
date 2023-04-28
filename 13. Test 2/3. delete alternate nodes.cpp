#include <iostream>
/* Given a Singly Linked List of integers, 
delete all the alternate nodes in the list. */

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        if(next) {
            delete next;
        }
    }
};

using namespace std;

void deleteAlternateNodes(Node *head) {
    if (head == NULL || head -> next == NULL) {
        return;
    }
    Node *prev = head;
    Node *temp = head -> next;
    while (temp != NULL) {
    	if (temp -> next == NULL) {
            prev -> next = NULL;
            return;
        } else {
     		prev -> next = temp -> next;
      	 	prev = prev -> next;
      		temp = prev -> next;
		}
    }
}

Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}
