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

using namespace std;

Node* mergeTwoLLs(Node *head1, Node *head2) {
    Node *h1 = head1;
    Node *h2 = head2;
    Node *head;
    Node *tail;
    
    if (h1 -> data >= h2 -> data) {
        head = h2;
        tail = h2;
        h2 = h2 -> next;
    } else {
        head = h1;
        tail = h1;
        h1 = h1 -> next;
    }
    
    while (h1 != NULL && h2 != NULL) {
        if (h1 -> data >= h2 -> data) {
            tail -> next = h2;
            tail = h2;
            h2 = h2 -> next;
        } else {
            tail -> next = h1;
            tail = h1;
            h1 = h1 -> next;
        }
    }
    
    while (h1 != NULL && h2 == NULL) {
        tail -> next = h1;
        tail = h1;
        h1 = h1 -> next;
    }
    
    while (h2 != NULL && h1 == NULL) {
        tail -> next = h2;
        tail = h2;
        h2 = h2 -> next;
    }
    return head;
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
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}
