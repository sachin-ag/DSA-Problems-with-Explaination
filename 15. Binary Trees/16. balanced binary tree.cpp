// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
#include <iostream>
#include <queue>
/* Given a binary tree, check if its balanced i.e. 
depth of left and right subtrees of every node differ by at max 1. 
Return true if given binary tree is balanced, false otherwise. */

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height(root -> left), height(root -> right));
}

bool isBalanced(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return true;
    }
    int leftH = height(root -> left);
    int rightH = height(root -> right);
    int heightDiff = leftH - rightH;
    if (heightDiff == 1 || heightDiff == 0 || heightDiff == -1) {
        if (isBalanced(root -> left) && isBalanced(root -> right)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
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
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	cout << "false" << endl;
}
