package hr.statistics;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {
    static List<Integer> readInput() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> list = new ArrayList();

        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }

        return list;
    }

    static double mean(List<? extends Number> list) {
        return list.stream().mapToInt(Number::intValue).average().getAsDouble();
    }

    static double round(double val, int scale, RoundingMode roundingMode) {
        return new BigDecimal(val).setScale(scale, roundingMode).doubleValue();
    }

    static BigDecimal bd(double val) {
        return new BigDecimal(val);
    }

    static BigDecimal mapReduce(List<? extends Number> list, BigDecimal mean) {
        return bd(list
                .stream()
                .map(x -> Math.pow(x.doubleValue() - mean.doubleValue(), 2.0))
                .reduce((a, b) -> a + b).get());
    }

    static double standardDeviation(List<? extends Number> list) {
        BigDecimal mean = new BigDecimal(mean(list));
        return round(Math.sqrt(mapReduce(list, mean).divide(bd(list.size())).doubleValue()),
                1,
                RoundingMode.HALF_UP);
    }

    public static void main(String[] args) {
        List<Integer> list = readInput();
        double sd = standardDeviation(list);
        System.out.println(sd);
    }
}
