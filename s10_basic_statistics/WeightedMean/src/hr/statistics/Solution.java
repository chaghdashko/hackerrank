package hr.statistics;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Solution {
    private static TupleList readInput() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        List<Integer> l1 = new ArrayList();
        for (int i = 0; i < n; i++) {
            l1.add(scanner.nextInt());
        }

        List<Integer> l2 = new ArrayList();
        for (int i = 0; i < n; i++) {
            l2.add(scanner.nextInt());
        }

        return new TupleList(l1, l2);
    }

    static double round(double val, int scale, RoundingMode roundingMode) {
        return new BigDecimal(val).setScale(scale, roundingMode).doubleValue();
    }

    static double weightedMean(List<Integer> l1, List<Integer> l2) {
        int weightedSum = IntStream.range(0, Math.min(l1.size(), l2.size())).map(i -> l1.get(i) * l2.get(i)).sum();
        int divisor = l2.stream().mapToInt(Integer::intValue).sum();
        double weightedMean = (double) weightedSum / divisor;
        return round(weightedMean, 1, RoundingMode.HALF_UP);
    }

    public static void main(String[] args) {
        TupleList t = readInput();
        System.out.println(weightedMean(t.l1, t.l2));
    }

    static class TupleList {
        List l1;
        List l2;

        TupleList(List l1, List l2) {
            this.l1 = l1;
            this.l2 = l2;
        }
    }
}
