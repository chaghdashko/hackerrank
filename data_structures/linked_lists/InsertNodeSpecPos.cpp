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

Node * InsertNth(Node * head, int data, int position) {
	if (head == NULL) {
		head = new struct Node;
		head->data = data;
		head->next = NULL;
		return head;
	} else {
		struct Node * newNode = new struct Node;
		newNode->data = data;

		if (position == 0)   // insert into head
				{
			newNode->next = head;
			head = newNode;
		} else {
			struct Node * node = head;
			int index = 0;

			while (true) {
				if (position == index + 1) {
					newNode->next = node->next;
					node->next = newNode;
					break;
				} else {
					node = node->next;
					index++;
				}
			}
		}

		return head;
	}
}

int main() {
	return 0;
}
