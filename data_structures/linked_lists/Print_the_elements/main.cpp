/*
 * main.cpp
 *
 *  Created on: 5 Tem 2016
 *      Author: cagdasko
 */

#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void Print(Node * head) {
	Node * node = head;

	while (node != NULL) {
		cout << node->data << endl;
		node = node->next;
	}
}

int main() {
	return 0;
}

