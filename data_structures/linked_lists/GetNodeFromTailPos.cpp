struct Node
{
 int data;
 struct Node *next;
}

int GetNode(Node * head, int positionFromTail) {
    int count = 0;
    
    Node * node = head;
    
    while (node != NULL) {
        count += 1;
        node = node->next;
    }
    
    int elem[count];
    int i = 0;
    
    node = head;
    
    while (node != NULL) {
        elem[i] = node->data;
        i++;
        node = node->next;
    }
    
    return elem[count - 1 - positionFromTail];
}

int main() {
	Node * node = new Node;
	node->data = 5;
	node->next = NULL;
	GetNode(node, pos);
	
	return 0;
	
	// Test not implemented
}