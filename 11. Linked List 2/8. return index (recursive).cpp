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

int indexOfNRecursive(Node *head, int n) {
    if (head == NULL) {
        return -1;
    }
    if (head -> data == n) {
        return 0;
    } else {
        int a = indexOfNRecursive(head -> next, n);
        if (a == -1) {
            return -1;
        } else {
            return 1 + a;
        }
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
    int n;
    cin >> n;
    cout << indexOfNRecursive(head, n);
    
}
