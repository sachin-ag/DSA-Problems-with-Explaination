#include <iostream>
#include <queue>
/* You are given a Binary Tree of type integer, 
a target node, and an integer value K.

Print the data of all nodes that have a distance K from the target node. 
The order in which they would be printed will not matter.*/

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

void printNodesAtDepthK(BinaryTreeNode<int>* root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 0) {
        cout << root -> data << endl;
    } else {
        printNodesAtDepthK(root -> left, k - 1);
        printNodesAtDepthK(root -> right, k - 1);
    }
}

int helper(BinaryTreeNode<int>* root, int Node, int k) { // returns dist bw root and Node
    if (root == NULL) {
        return -1;
    }
    if (root -> data == Node) {
        printNodesAtDepthK(root, k);
        return 0;
    }
    int lD = helper(root -> left, Node, k);
    if (lD != -1) {
        if (lD + 1 == k) {
            cout << root -> data << endl;
        } else {
            printNodesAtDepthK(root -> right, k - lD - 2);
        }
        return lD + 1;
    }
    int rD = helper(root -> right, Node, k);
    if (rD != -1) {
        if (rD + 1 == k) {
            cout << root -> data << endl;
        } else {
            printNodesAtDepthK(root -> left, k - rD - 2);
        }
        return rD + 1;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int a = helper(root, node, k);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
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
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
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
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}