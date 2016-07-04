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
  if (head == NULL) {
      head = (Node *) malloc(sizeof(struct Node));
      head->data = data;
      head->next = NULL;
  } else {
      Node * tail = head;

      while (true) {
          if (tail->next == NULL) { // This is the tail, append to this
              Node * newNode = (Node *) malloc(sizeof(struct Node));
              newNode->data = data;
              newNode->next = NULL;
              tail->next = newNode;
              break;
          }

          tail = tail->next;
      }
  }

  return head;
}

int main() {
	return 0;
}
