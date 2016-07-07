public class CompareLinkedLists {

    CompareLinkedLists() {
        Node node1 = new Node();
        node1.data = 1;

        Node node2 = new Node();
        node2.data = 1;

        Node node3 = new Node();
        node3.data = 1;

        Node node4 = new Node();
        node4.data = 2;

        System.out.println(CompareLists(node1, node2));
        System.out.println(CompareLists(node3, node4));
    }

    public static void main(String[] args) {
        new CompareLinkedLists();
    }

    int CompareLists(Node headA, Node headB) {
        if (headA == null && headB == null)
            return 1;

        if (headA == null || headB == null)
            return 0;

        Node nodeA = headA;
        Node nodeB = headB;

        while (true) {
            if (nodeA == null && nodeB == null)
                break;

            if (nodeA == null || nodeB == null)
                return 0;

            if (nodeA.data != nodeB.data)
                return 0;

            nodeA = nodeA.next;
            nodeB = nodeB.next;
        }

        return 1;
    }
}

class Node {
    int data;
    Node next;
}
