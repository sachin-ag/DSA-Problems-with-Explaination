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
class Pair {
    public:
    TreeNode<int>* max;
    TreeNode<int>* smax;
};

Pair helper(TreeNode<int>* root) {
    Pair ans;
    ans.max = root;
    ans.smax = NULL;
    for (int i=0; i<root->children.size(); i++) {
        Pair temp = helper(root -> children[i]);
        if (ans.max -> data > temp.max -> data) {
            if (ans.smax == NULL || ans.smax -> data < temp.max -> data) {
                ans.smax = temp.max;
            }
        } else if (ans.max -> data < temp.max -> data) {
            TreeNode<int>* x = ans.max;
            ans.max = temp.max;
            if (temp.smax == NULL || x -> data > temp.smax -> data) {
                ans.smax = x;
            } else {
                ans.smax = temp.smax;
            }
        }
    }
    return ans;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    Pair p = helper(root);
    return p.smax;
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
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}

