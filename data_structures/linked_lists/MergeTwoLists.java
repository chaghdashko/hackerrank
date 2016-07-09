import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Node {
    int data;
    Node next;
}

public class MergeTwoLists {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int list1Len = scanner.nextInt();
        List<Node> list1 = new ArrayList<>(list1Len);

        for (int j = 0; j < list1Len; j++) {
            Node node = new Node();
            node.data = scanner.nextInt();
            node.next = null;
            list1.add(node);
        }

        for (int j = 0; j < list1Len; j++) {
            if (j == list1Len - 1)
                list1.get(j).next = null;
            else
                list1.get(j).next = list1.get(j + 1);
        }

        int list2Len = scanner.nextInt();
        List<Node> list2 = new ArrayList<>(list2Len);

        for (int j = 0; j < list2Len; j++) {
            Node node = new Node();
            node.data = scanner.nextInt();
            node.next = null;
            list2.add(node);
        }

        for (int j = 0; j < list2Len; j++) {
            if (j == list2Len - 1)
                list2.get(j).next = null;
            else
                list2.get(j).next = list2.get(j + 1);
        }

        Node res = MergeLists(list1.get(0), list2.get(0));
        Node node = res;

        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }

        System.out.println();
    }

    static Node MergeLists(Node headA, Node headB) {
        if (headA == null && headB == null)
            return null;

        if (headA == null || headB == null)
            return ((headA == null) ? headB : headA);

        Node nodeA = headA;
        Node tmp = null;
        Node prev = null;

        while (nodeA != null) {
            Node nodeB = headB;
            prev = null;
            boolean isNodeChanged = false;

            while (nodeB != null) {
                if (nodeA.data < nodeB.data) {
                    if (prev != null)
                        prev.next = nodeA;
                    else
                        headB = nodeA;

                    tmp = nodeA.next;
                    nodeA.next = nodeB;
                    isNodeChanged = true;
                    break;
                }

                prev = nodeB;
                nodeB = nodeB.next;
            }

            if (!isNodeChanged) {
                prev.next = nodeA;
                nodeA = nodeA.next;
            } else
                nodeA = tmp;
        }

        return ((headA.data < headB.data) ? headA : headB);
    }
}
