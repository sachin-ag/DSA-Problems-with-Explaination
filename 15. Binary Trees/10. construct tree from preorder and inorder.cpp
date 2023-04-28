/*
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
*/
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    if (preLength == 0) {
        return NULL;
    }
    int rootData;
    rootData = preorder[0];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    int rootIndex = 0;
    while (rootIndex < inLength) {
        if (inorder[rootIndex] == rootData) {
            break;
        } else {
            rootIndex++;
        }
    }
    int leftLength = rootIndex;
    int rightLength = preLength - rootIndex - 1;
    int *leftPre = new int[leftLength];
    int *leftIn = new int[leftLength];
    int *rightPre = new int[leftLength];
    int *rightIn = new int[leftLength];
    for (int i=0; i<leftLength; i++) {
    	leftPre[i] = preorder[i+1];
	}
	for (int i=0; i<leftLength; i++) {
    	leftIn[i] = inorder[i];
	}
	for (int i=0; i<rightLength; i++) {
    	rightPre[i] = preorder[i+leftLength+1];
	}
	for (int i=0; i<rightLength; i++) {
    	rightIn[i] = inorder[i+leftLength+1];
	}
    root -> left = buildTree(leftPre, leftLength, leftIn, leftLength);
    root -> right = buildTree(rightPre, rightLength, rightIn, rightLength);
    return root;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}

