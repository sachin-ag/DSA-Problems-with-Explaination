// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
#include <iostream>
#include <queue>
#include <climits>

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

class isBSTHelp {
	public:
		int minimum;
		int maximum;
		bool isBST;
};

isBSTHelp isBST2(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		isBSTHelp ans;
		ans.isBST = true;
		ans.minimum = INT_MAX;
		ans.maximum = INT_MIN;
		return ans; 
	}
	isBSTHelp leftAns = isBST2(root -> left);
	isBSTHelp rightAns = isBST2(root -> right);
	isBSTHelp ans;
	ans.minimum = min(root -> data, min(leftAns.minimum, rightAns.minimum));
	ans.maximum = max(root -> data, max(leftAns.maximum, rightAns.maximum));
	ans.isBST = ((root -> data > leftAns.maximum) && (root -> data <= rightAns.minimum) && leftAns.isBST && rightAns.isBST);
	return ans;
}

bool isBST(BinaryTreeNode<int> *root) {
    isBSTHelp temp = isBST2(root);
    return temp.isBST;
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
    if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete root;
}

