struct Node {
	int data;
	struct Node * next;
	struct Node * prev;
}

Node* SortedInsert(Node *head, int data)
{
	Node * node = new Node;
	node->data = data;

	if (head == nullptr)
	{
		node->next = nullptr;
		node->prev = nullptr;
		return node;
	}

	if (node->data < head->data)
	{
		node->prev = nullptr;
		node->next = head;
		head->prev = node;
		return node;
	}

	Node * index = head;

	while (index != nullptr)
	{
		if (index->next == nullptr)
		{
			node->next = index->next;
			node->prev = index;
			index->next = node;

			break;
		}
		else if ((node->data >= index->data) && (node->data < index->next->data))
		{
			node->next = index->next;
			node->prev = index;

			if (index->next != nullptr)
			{
				index->next->prev = node;
			}

			index->next = node;

			break;
		}
		else
			index = index->next;
	}

	return head;
}

int main() {
	return 0;
}