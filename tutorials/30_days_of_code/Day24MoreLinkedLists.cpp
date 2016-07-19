//============================================================================
// Name        : Day24MoreLinkedLists.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int d) {
		data = d;
		next = NULL;
	}
};

class Solution {
public:

	/*
	 * List is assumed to be in ascending order, i.e,
	 * { 1, 2, 3, 3, 4, 5, 6, 6, 7 }
	 */
	Node* removeDuplicates(Node *head) {
		if (head != NULL) {
			Node* node = head;

			while (node->next != NULL) {
				if (node->data == node->next->data) {
					Node * node2Del = node->next;
					node->next = node->next->next;
					delete node2Del;

					/*
					 * We traverse the list until we find a different
					 * next node
					 */
					continue;
				}

				node = node->next;
			}
		}

		return head;
	}

	Node* insert(Node *head, int data) {
		Node* p = new Node(data);

		if (head == NULL) {
			head = p;
		} else if (head->next == NULL) {
			head->next = p;
		} else {
			Node *start = head;

			while (start->next != NULL)
				start = start->next;

			start->next = p;
		}

		return head;
	}

	void display(Node *head) {
		Node *start = head;

		while (start) {
			cout << start->data << " ";
			start = start->next;
		}
	}
};

int main() {
	Node* head = NULL;
	Solution mylist;
	int T, data;
	cin >> T;

	while (T-- > 0) {
		cin >> data;
		head = mylist.insert(head, data);
	}

	head = mylist.removeDuplicates(head);
	mylist.display(head);

	return 0;
}
