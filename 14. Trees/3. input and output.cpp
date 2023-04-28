#include <iostream>
using namespace std;
#include "TreeNode.h"

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter Data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of root" << endl;
	cin >> n;
	for (int i=0; i<n; i++) {
		TreeNode<int>* child = takeInput();
		root -> children.push_back(child);
	}
	return root;
}

void printTree (TreeNode<int>* root) {
	if (root == NULL) { // this is not a base case
		return;
	}
	cout << root -> data << ": ";
	for (int i=0; i<root -> children.size(); i++) {
		cout << root -> children[i] -> data << ", ";
	}
	cout << endl;
	for (int i=0; i<root -> children.size(); i++) {
		printTree(root -> children[i]);
	}
}

int main () {
	/*TreeNode<int>* root = new TreeNode<int>(10);
	TreeNode<int>* node1 = new TreeNode<int>(20);
	TreeNode<int>* node2 = new TreeNode<int>(30);
	TreeNode<int>* node3 = new TreeNode<int>(40);
	root -> children.push_back(node1);
	root -> children.push_back(node2);
	root -> children.push_back(node3);
	printTree(root);*/
	
	TreeNode<int>* root = takeInput();
	printTree(root); 
	return 0;
}
