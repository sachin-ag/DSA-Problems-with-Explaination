#include <iostream>
using namespace std;
#include "TreeNode.h"

int main () {
	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(1);
	TreeNode<int>* node2 = new TreeNode<int>(1);
	TreeNode<int>* node3 = new TreeNode<int>(1);
	root -> children.push_back(node1);
	root -> children.push_back(node2);
	root -> children.push_back(node3);
	return 0;
	}

