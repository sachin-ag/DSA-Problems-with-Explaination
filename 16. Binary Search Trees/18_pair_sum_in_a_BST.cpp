// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
#include <iostream>
#include <queue>
/* Given a binary search tree and an integer S, 
find pair of nodes in the BST which sum to S. 
You can use extra space only O(log n). */

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

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;

void BSTtoVector(BinaryTreeNode<int>* root, vector<int>* v) {
    if (root == NULL) {
        return;
    }
    BSTtoVector(root -> left, v);
    v -> push_back(root -> data);
    BSTtoVector(root -> right, v);
}

void printNodesSumToS(BinaryTreeNode<int>* root, int s) {
    if (root == NULL) {
        return;
    }
    vector<int>* v = new vector<int>;
    BSTtoVector(root, v);
    int i=0, j=v->size()-1;
    while (i < j) {
        if (v -> at(i) + v -> at(j) == s) {
            cout << v -> at(i) << " " << v -> at(j) << endl;
            i++;
            j--;
        } else if (v -> at(i) + v -> at(j) < s) {
            i++;
        } else if (v -> at(i) + v -> at(j) > s) {
            j--;
        }
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
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}
