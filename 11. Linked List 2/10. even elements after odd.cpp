//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;

node* arrange_LinkedList(node* head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    node* oddHead = NULL;
    node* oddTail = NULL;
    node* evenHead = NULL;
    node* evenTail = NULL;
    while (head != NULL) {
        if (head -> data % 2 != 0) {
            if (oddHead == NULL) {
                oddHead = head;
                oddTail = head;
            } else {
                oddTail -> next = head;
                oddTail = head;
            }
        } else {
            if (evenHead == NULL) {
                evenHead = head;
                evenTail = head;
            } else {
                evenTail -> next = head;
                evenTail = head;
            }
        }
        head = head -> next;
    }
    oddTail -> next == NULL;
    if (evenHead == NULL) {
    	return oddHead;
	}
    evenTail -> next = NULL;
    if (oddHead == NULL) {
        return evenHead;
    }
    oddTail -> next = evenHead;
    return oddHead;
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
