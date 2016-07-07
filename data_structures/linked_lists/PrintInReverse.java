import java.util.ArrayList;
import java.util.List;

class Node {
    int data;
    Node next;
}

public class PrintInReverse {

    PrintInReverse() {
        Node node1 = new Node();
        node1.data = 1;

        Node node2 = new Node();
        node2.data = 2;

        Node node3 = new Node();
        node3.data = 3;

        node1.next = node2;
        node2.next = node3;
        node3.next = null;

        ReversePrint(node1);
    }

    public static void main(String[] args) {
        new PrintInReverse();
    }

    void ReversePrint(Node head) {
        List list = new ArrayList<>();

        Node node = head;

        while (node != null) {
            list.add(node.data);
            node = node.next;
        }

        for (int i = list.size() - 1; i >= 0; i--) {
            System.out.println(list.get(i));
        }
    }
}
