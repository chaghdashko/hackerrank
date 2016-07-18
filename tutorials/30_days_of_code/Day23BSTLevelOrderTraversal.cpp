//============================================================================
// Name        : Day23BSTLevelOrderTraversal.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

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

	/*
	 * Level-Order Traversal (Hackerrank explanation)
	 *
	 * A level-order traversal of tree t is a recursive algorithm that
	 * processes the root, followed by the children of the root (from left
	 * to right), followed by the grandchildren of the root (from left to
	 * right), etc. The basic algorithm shown below uses a queue of references
	 * to binary trees to keep track of the subtrees at each level.
	 */
	void levelOrder(Node * root) {
		if (root != NULL) {
			queue<Node *> q;
			q.push(root);

			while (!q.empty()) {
				Node * node = q.front();
				q.pop();

				cout << node->data << " ";

				if (node->left != NULL)
					q.push(node->left);

				if (node->right != NULL)
					q.push(node->right);
			}
		}
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

	myTree.levelOrder(root);

	return 0;
}
