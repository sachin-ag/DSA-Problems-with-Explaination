// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1 15
#include <iostream>
#include <queue>
// Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

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
    	if(left) {
     		delete left;
    	}
	if(right) {
     		delete right;
    	}
    }
};

using namespace std;

void Merge(int l[], int r[], int a[], int n1, int n2) {
	int i = 0, j = 0, k = 0;
	while ((i<n1)&&(j<n2)) {
		if (l[i] < r[j]) {
			a[k++] = l[i++];
		} else {
			a[k++] = r[j++];
		}
	}
	while (i<n1) {
		a[k++] = l[i++];
	}
	while (j<n2) {
		a[k++] = r[j++];
	}
}

void mergeSort(int input[], int size){
    if (size<=1) {
        return;
    } else {
        int m = size/2;
        int a[m];
        int b[size-m];
        for (int i=0; i<m; i++) {
            a[i] = input[i];
        }
        for (int i=m; i<size; i++) {
            b[i-m] = input[i];
        }
        mergeSort(a, m);
        mergeSort(b, size-m);
        Merge(a, b, input, m, size-m);
    }
}

int numOfNodes(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + numOfNodes(root -> left) + numOfNodes(root -> right);
}

void treeToArray(BinaryTreeNode<int>* root, int array[]) {
    if (root == NULL) {
        return;
    }
    treeToArray(root -> left, array);
    treeToArray(root -> right, array);
    int i=0;
    while (array[i] != -1) {
        i++;
    }
    array[i] = root -> data;
}

void nodesSumToS(BinaryTreeNode<int>* root, int sum) {
    if (root == NULL) {
        return;
    }
    int size = numOfNodes(root);
    int treeArray[size];
    for (int i=0; i<size; i++) {
        treeArray[i] = -1;
    }
    treeToArray(root, treeArray);
    mergeSort(treeArray, size);
    int i=0, j=size-1;
    while (i < j) {
        if (i >= j) {
            break;
        }
        if (treeArray[i] + treeArray[j] == sum) {
            cout << treeArray[i] << " " << treeArray[j] << endl;
            i++;
            j--;
        } else if (treeArray[i] + treeArray[j] < sum) {
            i++;
        } else {
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

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}
