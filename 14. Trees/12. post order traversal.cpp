// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
#include <iostream>
using namespace std;
#include <vector>
#include <queue>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};

void preOrder(TreeNode<int>* root) {
	cout << root -> data << " ";
	for (int i=0; i<root -> children.size(); i++) {
		preOrder(root -> children[i]);
	}
}

void postOrder(TreeNode<int>* root) {
	for (int i=0; i<root -> children.size(); i++) {
		postOrder(root -> children[i]);
	}
	cout << root -> data << " ";
}

int numLeafNodes(TreeNode<int>* root) {
    if (root -> children.size() == 0) {
        return 1;
    }
    int ans = 0;
    for (int i=0; i<root->children.size(); i++) {
        ans += numLeafNodes(root -> children[i]);
    }
    return ans;
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

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    preOrder(root);
    cout << endl;
    postOrder(root);
}

