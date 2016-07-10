#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	struct Node * next;
}

Node * RemoveDuplicates(Node * head) {
	if (head != NULL) {
		Node * node = head;

		while (node->next != NULL) {
			if (node->data == node->next->data) {
				Node * tmp = node->next;
				node->next = node->next->next;
				delete tmp;
				continue;
			}

			node = node->next;
		}
	}

	return head;
}

int main() {
	return 0;

	// test cases not implemented
}