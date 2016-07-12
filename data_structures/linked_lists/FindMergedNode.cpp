struct Node {
    int data;
    struct Node* next;
}

int FindMergeNode(Node *headA, Node *headB)
{
    Node * nodeA = headA;

    while (nodeA != nullptr) {
        Node * nodeB = headB;
        bool isMergePointFound = false;

        while (nodeB != nullptr) {
            if (nodeB == nodeA) {
                return nodeB->data;
            }

            nodeB = nodeB->next;
        }

        nodeA = nodeA->next;
    }

    return 0;
}

int main() {
    return 0;
}