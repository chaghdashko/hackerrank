package hr.statistics;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
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

    public static void main(String[] args) {
        List<Integer> list = readInput();
        list = list.stream().sorted().collect(Collectors.toList());

        Quartiles<Integer> quartiles = new Quartiles<>(list);

        System.out.println(((int) quartiles.getQ1()));
        System.out.println(((int) quartiles.getQ2()));
        System.out.println(((int) quartiles.getQ3()));
    }
}

class Quartiles<T extends Number> {
    double q1;
    double q2;
    double q3;
    List<T> list;

    Quartiles(List<T> list) {
        this.list = list;
        List<T> lowerHalf = list.subList(0, list.size() / 2);
        List<T> upperHalf = list.subList(getUpperHalfStartIndex(list.size()), list.size());
        this.q1 = median(lowerHalf);
        this.q2 = median(list);
        this.q3 = median(upperHalf);
    }

    int getUpperHalfStartIndex(int n) {
        return ((n % 2) != 0) ? (n / 2) + 1 : n / 2;
    }

    double median(List<T> list) {
        list = list.stream().sorted().collect(Collectors.toList());
        int n = list.size();

        return (n % 2 != 0)
                ? list.get(n / 2).doubleValue()
                : (list.get(n / 2).doubleValue() + list.get((n / 2) - 1).doubleValue()) / 2;
    }

    public double getQ1() {
        return q1;
    }

    public double getQ2() {
        return q2;
    }

    public double getQ3() {
        return q3;
    }
}