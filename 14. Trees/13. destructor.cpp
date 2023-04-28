// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
#include <iostream>
using namespace std;
#include "TreeNode.h"
#include <queue>

void deleteTree(TreeNode<int>* root) {
	for (int i=0; i<root->children.size(); i++) {
		deleteTree(root -> children[i]);
	}
	delete root;
}

void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    cout << endl;
    while(!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << ":";
        for (int i=0; i<front -> children.size(); i++) {
            cout << front -> children[i] -> data;
            if (i < front -> children.size() - 1) {
                cout<<",";
            }
            pendingNodes.push(front -> children[i]);
        }
        cout << endl;
    }
}

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data: " << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while (!pendingNodes.empty()) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter no. of children of " << front -> data << endl;
		int numChild;
		cin >> numChild;
		for (int i=0; i<numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front -> data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front -> children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

int main () {
	TreeNode<int>* root = takeInputLevelWise();
	// deleteTree(root);
	delete root; // using destructor mentioned in TreeNode.h file
	return 0;
	}

