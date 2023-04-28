
#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

int numberOfNodes (BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + numberOfNodes(root -> left) + numberOfNodes(root -> right);
}

void printTreeLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << ":";
        if (front -> left != NULL) {
            cout << "L:" << front -> left -> data << ",";
            pendingNodes.push(front -> left);
        } else {
            cout << "L:-1,";
        }
        if (front -> right != NULL) {
            cout << "R:" << front -> right -> data;
            pendingNodes.push(front -> right);
        } else {
            cout << "R:-1";
        }
        cout << endl;
    }
}

BinaryTreeNode<int>* takeInputLevelWise() {
	int data;
	cout << "Enter root data" << endl;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
	
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty()) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front -> data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front -> left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front -> data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front -> right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

int main () {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << numberOfNodes(root);
	delete root;
	return 0;
	}
