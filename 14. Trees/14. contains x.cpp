// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
#include <iostream>
using namespace std;
#include <vector>

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


#include <queue>

bool containsX(TreeNode<int>* root, int x) {
    if (root -> data == x) {
        return true;
    }
    int truth = 0;
    for (int i=0; i<root->children.size(); i++) {
        truth += containsX(root -> children[i], x);
    }
    if (truth > 0) {
        return true;
    } else {
        return false;
    }
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    int x;
    cin >> x;
    TreeNode<int>* root = takeInputLevelWise();
    if(containsX(root, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

