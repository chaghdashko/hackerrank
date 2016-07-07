import java.util.ArrayList;
import java.util.List;

public class ReverseALinkedList {

    ReverseALinkedList() {
        Node node1 = new Node();
        node1.data = 1;

        Node node2 = new Node();
        node2.data = 2;

        Node node3 = new Node();
        node3.data = 3;

        node1.next = node2;
        node2.next = node3;
        node3.next = null;

        Node head = Reverse(node1);
        System.out.println(head.data + " " + head.next.data + " " + head.next.next.data);
    }

    public static void main(String[] args) {
        new ReverseALinkedList();
    }

    Node Reverse(Node head) {
        if (head == null || head.next == null)
            return head;

        Node node = head;
        List<Node> list = new ArrayList<Node>();

        while (node != null) {
            list.add(node);
            node = node.next;
        }

        Node newHead = list.get(list.size() - 1);

        for (int i = list.size() - 1; i >= 0; i--) {
            if (i == 0)
                list.get(i).next = null;
            else
                list.get(i).next = list.get(i - 1);
        }

        return newHead;
    }
}

class Node {
    int data;
    Node next;
}
