// 2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1 13
#include <iostream>
#include <queue>
#include <string>
/* For a given Binary Tree of type integer and a number K, 
print out all root-to-leaf paths where the sum of all the 
node data along the path is equal to K. */

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

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

void helper(BinaryTreeNode<int>* root, int k, string s) {
    if (root == NULL) {
        return;
    }
    s += to_string(root -> data);
    s += " ";
    if (root -> left == NULL && root -> right == NULL) {
        if (k - root -> data == 0) {
            cout << s << endl;
        }
    } else {
        helper(root -> left, k - root -> data, s);
        helper(root -> right, k - root -> data, s);
    }
}

void rootToLeafPathsSumToK(BinaryTreeNode<int>* root, int k) {
    string s;
    helper(root, k, s);
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
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}