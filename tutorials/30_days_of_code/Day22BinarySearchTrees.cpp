//============================================================================
// Name        : Day22BinarySearchTrees.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;

	Node(int d) {
		data = d;
		left = right = NULL;
	}
};

class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		} else {
			Node* cur;

			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			} else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}

	int getHeight(Node* root) {
		if (root == NULL)
			return 0;

		if (root->left == NULL && root->right == NULL)
			return 0;

		int lHeigt = getHeight(root->left);
		int rHeigt = getHeight(root->right);

		if (lHeigt > rHeigt)
			return (lHeigt + 1);

		return (rHeigt + 1);
	}
};

int main() {
	Solution myTree;
	Node* root = NULL;
	int T, data;
	cin >> T;

	while (T-- > 0) {
		cin >> data;
		root = myTree.insert(root, data);
	}

	int height = myTree.getHeight(root);
	cout << height;

	return 0;
}
