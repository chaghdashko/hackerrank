package hr.statistics;

import java.util.*;
import java.util.stream.Collectors;

public class Solution {
    private static List<Integer> readInput() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> list = new ArrayList();

        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }

        return list;
    }

    private static double mean(List<Integer> list) {
        return list.stream().mapToInt(Integer::intValue).average().getAsDouble();
    }

    private static double median(List<Integer> list) {
        double median;
        int n = list.size();

        list = list.stream().sorted().collect(Collectors.toList());

        if (n % 2 != 0) {
            median = list.get(n / 2);
        } else {
            median = (double) (list.get(n / 2) + list.get((n / 2) - 1)) / 2;
        }

        return median;
    }

    private static int mode(List<Integer> list) {
        Map<Integer, List<Integer>> freqMap = new HashMap<>();

        for (Integer item : list) {
            int freq = Collections.frequency(list, item);

            if (freqMap.containsKey(freq)) {
                freqMap.get(freq).add(item);
            } else {
                List<Integer> tmpList = new ArrayList<>();
                tmpList.add(item);
                freqMap.put(freq, tmpList);
            }
        }

        int key = freqMap.keySet().stream().mapToInt(Integer::intValue).max().getAsInt();
        return freqMap.get(key).stream().mapToInt(Integer::intValue).min().getAsInt();
    }

    public static void main(String[] args) {
        List<Integer> list = readInput();
        System.out.println(mean(list));
        System.out.println(median(list));
        System.out.println(mode(list));
    }
}
