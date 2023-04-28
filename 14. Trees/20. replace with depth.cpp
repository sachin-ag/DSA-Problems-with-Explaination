// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
#include <iostream>
using namespace std;
#include <vector>
// In a given Generic Tree, replace each node with its depth value.

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

void helper(TreeNode<int> *root, int n) {
    root -> data = n;
    for (int i=0; i<root->children.size(); i++) {
        helper(root -> children[i], n + 1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root){
    helper(root, 0);
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

void printLevelATNewLine(TreeNode<int> *root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        TreeNode<int> *first = q.front();
        q.pop();
        if(first == NULL) {
            if(q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first -> data << " ";
        for(int i = 0; i < first -> children.size(); i++) {
            q.push(first -> children[i]);
        }
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}

