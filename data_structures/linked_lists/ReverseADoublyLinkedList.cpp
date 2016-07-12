struct Node {
	int data;
	struct Node * next;
	struct Node * prev;
}

Node * Reverse(Node * head) {
	if ((head != nullptr) && (head->next != nullptr)) {
		Node * node = head;
		Node * last;

		while (node != nullptr) {
			Node * tmp = node->next;

			node->next = node->prev;
			node->prev = tmp;

			last = node;
			node = tmp;
		}

		head = last;
	}

	return head;
}


int main() {
	return 0;
}