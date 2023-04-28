#include <iostream>
using namespace std;

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

class BST {
    BinaryTreeNode<int>* root;

    public:
    BST() {
        root = NULL;
    }
    
    private:
    BinaryTreeNode<int>* insertHelp(int data, BinaryTreeNode<int>* root) {
        if (root == NULL) {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data > root -> data) {
            root -> right = insertHelp(data, root -> right);
        } else if ( data < root -> data) {
            root -> left = insertHelp(data, root -> left);
        }
        return root;
    }

    BinaryTreeNode<int>* minimum(BinaryTreeNode<int>* root) {
        if (root == NULL) {
            return NULL;
        }
        if (root -> left == NULL) {
            return root;
        } else {
            return minimum(root -> left);
        }
    }

    BinaryTreeNode<int>* deleteHelp(int data, BinaryTreeNode<int>* root) {
        if (root == NULL) {
            return NULL;
        }
        if (root -> data < data) {
            root -> right = deleteHelp(data, root -> right);
        } else if (root -> data > data) {
            root -> left = deleteHelp(data, root -> left);
        } else {
            if (root -> left == NULL && root -> right == NULL) {
                return NULL;
            } else if (root -> left == NULL && root -> right != NULL) {
                BinaryTreeNode<int>* temp = root -> right;
                return temp;
            }  else if (root -> left != NULL && root -> right == NULL) {
                BinaryTreeNode<int>* temp = root -> left;
                return temp;
            } else {
                BinaryTreeNode<int>* rightMinimum =  minimum(root -> right);
                root -> data = rightMinimum -> data;
                root -> right = deleteHelp(rightMinimum -> data, root -> right);
                return root;
            }
        }
        return root;
    }

    bool hasDataHelp(int data, BinaryTreeNode<int>* root) {
        if (root == NULL) {
            return false;
        }
        if (root -> data == data) {
            return true;
        } else if (data < root -> data) {
            return hasDataHelp(data, root -> left);
        } else {
            return hasDataHelp(data, root -> right);
        }
    }

    void printHelp(BinaryTreeNode<int>* root) {
        if (root == NULL) {
            return;
        }
        cout << root -> data << ":";
        if (root -> left != NULL) {
            cout << "L:" << root -> left -> data << ",";
        }
        if (root -> right != NULL) {
            cout << "R:" << root -> right -> data;
        }
        cout << endl;
        printHelp(root -> left);
        printHelp(root -> right);
    }

    public:
    void insert(int data) {
        this -> root = insertHelp(data, this -> root);
    }

    void deleteData(int data) {
        this -> root = deleteHelp(data, this -> root);
    }
    
    bool hasData(int data) {
        return hasDataHelp(data, root);
    }

    void printTree() {
        printHelp(this -> root);
    }
};

int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            //default:
                //tree->printTree();
                return 0;
                break;
        }
    }
}