/*
 * main.cpp
 *
 *  Created on: 5 Tem 2016
 *      Author: cagdasko
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node * Delete(Node * head, int position) {
	if (position == 0) {
		Node * newHead = head->next;
		delete head;
		return newHead;
	} else {
		int index = 0;
		Node * node = head;

		while (true) {
			if (index == (position - 1)) {
				Node * node2Del = node->next;
				node->next = node2Del->next;
				delete node2Del;
				break;
			} else {
				node = node->next;
			}

			index++;
		}

		return head;
	}
}

int main() {
	return 0;
}
