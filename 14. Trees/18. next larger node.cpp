// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
#include <iostream>
using namespace std;
#include <vector>
/* Given a generic tree and an integer n. 
Find and return the node with next larger element 
in the Tree i.e. find a node with value just greater than n. */

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
TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    TreeNode<int>* ans;
    if (root -> data > n) {
        ans = root;
    } else {
        ans = NULL;
    }
    for (int i=0; i<root->children.size(); i++) {
        TreeNode<int>* temp = nextLargerElement(root -> children[i], n);
        if (temp != NULL) {
            if (ans == NULL) {
          	  ans = temp;
     	   } else if (ans -> data > temp -> data) {
       	     ans = temp;
      	  }
        }
    }
    return ans;
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
    int n;
    cin >> n;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}

