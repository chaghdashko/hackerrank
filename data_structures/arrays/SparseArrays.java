import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SparseArrays {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nStrings = sc.nextInt();

        List<String> strings = new ArrayList<>();

        for (int i = 0; i < nStrings; i++) {
            strings.add(sc.next());
        }

        int nQueries = sc.nextInt();

        List<String> queries = new ArrayList<>();

        for (int i = 0; i < nQueries; i++) {
            queries.add(sc.next());
        }

        // Evaluate inputs
        for (String query: queries) {
            int count = 0;

            for (String item: strings)
                if (item.equals(query))
                    count++;

            System.out.println(count);
        }
    }
}
