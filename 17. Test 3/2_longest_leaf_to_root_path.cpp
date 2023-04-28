//  5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
#include <iostream>
#include <vector>
#include <queue>
// Given a binary tree, return the longest path from leaf to root. 
// Longest means, a path which contain maximum number of nodes from leaf to root.

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

vector<int>* longestPath(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        vector<int>* Ans = new vector<int>;
        return Ans;
    }
    vector<int>* leftVector = longestPath(root -> left);
    vector<int>* rightVector = longestPath(root -> right);
    if (leftVector -> size() >= rightVector -> size()) {
        leftVector -> push_back(root -> data);
        return leftVector;
    } else if (leftVector -> size() < rightVector -> size()) {
        rightVector -> push_back(root -> data);
        return rightVector;
    }
    return NULL;
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
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}