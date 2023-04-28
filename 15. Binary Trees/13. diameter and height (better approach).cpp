// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
#include <iostream>
#include <queue>
// diameter is max dist between two nodes

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

pair<int, int> heigthDiameter(BinaryTreeNode<int>* root) { // using built in pair class
	if (root == NULL) {
		pair<int, int> p;
		p.first = 0; // height
		p.second = 0; // diameter
		return p;
	}
	pair<int, int> leftAns = heigthDiameter(root -> left);
	pair<int, int> rightAns = heigthDiameter(root -> right);
	pair<int, int> p;
	p.first = 1 + max(leftAns.first, rightAns.first); // height
	p.second = max(leftAns.first + rightAns.second, max(leftAns.second, rightAns.second));
	return p;
} 

int diameter(BinaryTreeNode<int>* root) {
	pair<int, int> p = heigthDiameter(root);
	return p.second;
}

int height(BinaryTreeNode<int>* root) {
    pair<int, int> p = heigthDiameter(root);
	return p.first;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << height(root) << endl;
    cout << diameter(root) << endl;
}
