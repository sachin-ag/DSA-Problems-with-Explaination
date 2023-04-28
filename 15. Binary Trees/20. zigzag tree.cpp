// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

void zigZagOrder(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    stack<BinaryTreeNode<int>*> stack1, stack2;
    stack1.push(root);
    while(!stack1.empty() || !stack2.empty()) {
        while(!stack1.empty()) {
            BinaryTreeNode<int>* top = stack1.top();
            cout << top -> data << " ";
            if (top -> left != NULL) {
                stack2.push(top -> left);
            }
            if (top -> right != NULL) {
                stack2.push(top -> right);
            }
            stack1.pop();
        }
        cout << endl;
        while(!stack2.empty()) {
            BinaryTreeNode<int>* top = stack2.top();
            cout << top -> data << " ";
            if (top -> right != NULL) {
                stack1.push(top -> right);
            }
            if (top -> left != NULL) {
                stack1.push(top -> left);
            }
            stack2.pop();
        }
        cout << endl;
    }
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
