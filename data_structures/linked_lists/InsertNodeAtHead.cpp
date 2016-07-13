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

Node * Insert(Node * head, int data) {
	Node * newHead;

	if (head == NULL) {
		head = (Node *) malloc(sizeof(struct Node));
		head->data = data;
		head->next = NULL;
		newHead = head;
	} else {
		Node * newNode = (Node *) malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->next = head;
		newHead = newNode;
	}

	return newHead;
}

int main() {
	return 0;
}
