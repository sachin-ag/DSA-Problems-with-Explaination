// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
#include <iostream>
#include <queue>
#include <climits>
/* Given a Binary tree, find the largest BST subtree. 
That is, you need to find the BST with maximum height 
in the given binary tree. */

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

// fn to check whether given BT is BST
bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX) {
    if (root == NULL) {
        return true;
    }
    if (root -> data < min || root -> data > max) {
    	return false;
	}
	bool isLeftOK = isBST(root -> left, min, root -> data - 1);
	bool isRightOK = isBST(root -> right, root -> data, max);
	return isLeftOK && isRightOK;
}

int heightOfTree(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(heightOfTree(root -> left), heightOfTree(root -> right));
}

pair<int, int> largestBSTHelp(BinaryTreeNode<int>* root) {
    pair<int, int> ans;
    if (root == NULL) {
        ans.first = -1;
        ans.second = 0;
        return ans;
    }
    if (isBST(root)) {
        ans.first = root -> data;
        ans.second = heightOfTree(root);
        return ans;
    }
    pair<int, int> leftAns = largestBSTHelp(root -> left);
    pair<int, int> rightAns = largestBSTHelp(root -> right);
    if (leftAns.second >= rightAns.second) {
        return leftAns;
    } else {
        return rightAns;
    }
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int>* root) {
     pair<int, int> p = largestBSTHelp(root);
     return p.second;
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
    cout << largestBSTSubtree(root);
    delete root;
}
