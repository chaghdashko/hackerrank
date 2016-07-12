
struct Node {
    int data;
    struct Node* next;
}

bool has_cycle(Node* head) {
    bool isFound = false;

    if (head == nullptr || head->next == nullptr)
        return false;

    Node * node = head;
    int i = 0;

    while (node != nullptr) {
        i++;

        if (i > 100) {
            isFound = true;
            break;
        }

        node = node->next;
    }

    return isFound;
}

int main() {
    return 0;
}
