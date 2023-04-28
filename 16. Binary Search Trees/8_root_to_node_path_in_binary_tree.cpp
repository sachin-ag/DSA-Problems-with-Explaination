// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
#include <iostream>
using namespace std;
#include <queue>
#include <vector>

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

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root -> data == data) {
        vector<int>* output = new vector<int>;
        output -> push_back(root -> data);
        return output;
    }
    vector<int>* leftOutput = getRootToNodePath(root -> left, data);
    if (leftOutput != NULL) {
        leftOutput -> push_back(root -> data);
        return leftOutput;
    } else {
        vector<int>* rightOutput = new vector<int>;
        rightOutput = getRootToNodePath(root -> right, data);
        if (rightOutput == NULL) {
            return NULL;
        } else {
            rightOutput -> push_back(root -> data);
            return rightOutput;
        }
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
    int data;
    cin >> data;
    vector<int>* output = getRootToNodePath(root, data);
    for (int i=0; i<output -> size(); i++) {
        cout << output -> at(i) << " ";
    }
    delete output;
    delete root;
    return 0;
}