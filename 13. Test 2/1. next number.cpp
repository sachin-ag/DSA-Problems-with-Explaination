#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
/* Given a large number represented in the form of a linked list. 
Write code to increment the number by 1 in-place(i.e. without using extra space). */

using namespace std;

Node* NextLargeNumber(Node *head) {
    if (head -> next == NULL) {
        if (head -> data < 9) {
            head -> data ++;
            return head;
        } else {
            head -> data = 0;
            Node *newNode = new Node(1);
            newNode -> next = head;
            return newNode;
        }
    }
    Node *temp = head;
    while (temp -> next -> next != NULL) {
        temp = temp -> next;
    }
    if (temp -> next -> data < 9) {
        temp -> next -> data += 1;
        return head;
    } else {
        Node *a = temp -> next;
        temp -> next = NULL;
        head = NextLargeNumber(head);
        temp = head;
        while (temp -> next != NULL) {
        temp = temp -> next;
   		}
        temp -> next = a;
        a -> next = NULL;
        a -> data = 0;
        return head;
    }
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
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
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}
