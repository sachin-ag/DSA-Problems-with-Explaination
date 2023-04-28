// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
#include <iostream>
#include <queue>
/* Given a binary search tree and two nodes, 
find LCA(Lowest Common Ancestor) of the given 
two nodes in the BST. Read about LCA if you are 
having doubts about the definition. */

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
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if (root == NULL) {
        return false;
    } else if (root -> data == x) {
        return true;
    } else {
        return (isNodePresent(root -> left, x) || isNodePresent(root -> right, x));
    }
    return false;
}

int lcaInBST(BinaryTreeNode<int>* root, int a, int b) {
    if (root == NULL) {
        return -1;
    }
    if (root -> data == a || root -> data == b) {
        return root -> data;
    }
    bool x = isNodePresent(root, a);
    bool y = isNodePresent(root, b);
    if (!x && !y) {
        return -1;
    } else if (!x && y) {
        return b;
    } else if (x && !y) {
        return a;
    }
    if (a < root -> data && b < root -> data) {
        return lcaInBST(root -> left, a, b);
    } else if (a > root -> data && b > root -> data) {
        return lcaInBST(root -> right, a, b);
    } else {
        return root -> data;
    }
    return -1;
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
    int a, b;
    cin >> a >> b;
    cout << lcaInBST(root, a, b);
    delete root;
}
