// 5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1 2 4
#include <iostream>
#include <queue>
/* Given the binary Tree and two nodes say ‘p’ and ‘q’. 
Determine whether the two nodes are cousins of each other or not. 
Two nodes are said to be cousins of each other if they are 
at same level of the Binary Tree and have different parents.
Do it in O(n). */

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

int nodeLevel(BinaryTreeNode<int> *root, int p) {
    if (root == NULL) {
        return -1;
    }
    if (root -> data == p) {
        return 0;
    }
    int leftAns = nodeLevel(root -> left, p);
    int rightAns = nodeLevel(root -> right, p);
    if (leftAns != -1) {
        return 1 + leftAns;
    }
	if (rightAns != -1) {
        return 1 + rightAns;
    }
    return -1;
}

bool checkSameParent(BinaryTreeNode<int>* root, int p, int q) {
    if (root == NULL) {
        return false;
    }
    if (root -> left != NULL && root -> right != NULL) {
        if (root -> left -> data == p && root -> right -> data == q) {
            return true;
        } else if (root -> left -> data == q && root -> right -> data == p) {
            return true;
        } else {
            return (checkSameParent(root -> left, p , q) || checkSameParent(root -> right, p, q));
        }
    } else if (root -> left == NULL && root -> right != NULL) {
        return checkSameParent(root -> right, p, q);
    } else if (root -> left != NULL && root -> right == NULL) {
        return checkSameParent(root -> left, p, q);
    }
    return false;
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    if (root == NULL) {
        return false;
    }
    
    if (nodeLevel(root, p) == nodeLevel(root, q) && !checkSameParent(root, p, q)) {
        return true;
    } else {
        return false;
    }
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
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
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}