// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
#include <iostream>
#include <queue>
/* Given a binary tree and two nodes, find LCA 
(Lowest Common Ancestor) of the given two nodes in Binary Tree. 
Read about LCA if you are having doubts about the definition. */

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

int lcaBinaryTree(BinaryTreeNode<int>* root, int a, int b) {
    if (root == NULL) {
        return -1;
    }
    if (root -> data == a || root -> data == b) {
        return root -> data;
    }

    bool aL = isNodePresent(root -> left, a);
    bool aR = isNodePresent(root -> right, a);
    bool bL = isNodePresent(root -> left, b);
    bool bR = isNodePresent(root -> right, b);

    bool aPresent = aL || aR;
    bool bPresemt = bL || bR;

    bool c1 = aL && bR;
    bool c2 = bL && aR;
    bool c3 = aL && bL;
    bool c4 = aR && bR;

    if (!aPresent && !bPresemt) {
        return -1;
    } else if (!aPresent && bPresemt) {
        return b;
    } else if (aPresent && !bPresemt) {
        return a;
    } else {
        if (c1 || c2) {
        return root -> data;
        } else if (c3) {
           return lcaBinaryTree(root -> left, a, b);
        } else if (c4) {
           return lcaBinaryTree(root -> right, a, b);
        }
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
    cout << lcaBinaryTree(root, a, b);
    delete root;
}