import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DynamicArray {
    public static void main(String[] args) {
        int lastAns = 0;
        Scanner sc = new Scanner(System.in);

        int nSeq = sc.nextInt();
        int nQueries = sc.nextInt();

        List<List<Integer>> seqList = new ArrayList<>();

        for (int i = 0; i < nSeq; i++) {
            List<Integer> list = new ArrayList<>();
            seqList.add(list);
        }

        List<int[]> queryList = new ArrayList<>();

        for (int i = 0; i < nQueries; i++) {
            int[] arr = new int[3];

            for (int j = 0; j < arr.length; j++) {
                arr[j] = sc.nextInt();
            }

            queryList.add(arr);
        }

        // Evaluate queries
        for (int[] query : queryList) {
            int type = query[0];
            int index = query[1];
            int elem = query[2];

            int seqIndex = (index ^ lastAns) % nSeq;

            if (type == 1) {
                seqList.get(seqIndex).add(elem);
            } else if (type == 2) {
                lastAns = seqList.get(seqIndex).get(elem % seqList.get(seqIndex).size());
                System.out.println(lastAns);
            } else {
                
            }
        }
    }
}
