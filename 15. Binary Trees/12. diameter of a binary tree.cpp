// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
#include <iostream>
#include <queue>
// diameter is max dist between two nodes
// time complexicity of this approach is very high

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

int height(BinaryTreeNode<int>* root);

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int option1 = height(root -> left) + height(root -> right);
	int option2 = diameter(root -> left);
	int option3 = diameter(root -> right);
	return max(option1, max(option2, option3));
	
}

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int ans = 1;
    int hLeft = height(root -> left);
    int hRight = height(root -> right);
    if (hLeft >= hRight) {
        ans += hLeft;
    } else {
        ans += hRight;
    }
    return ans;
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
    cout << height(root);
}
