package hr.statistics;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Solution {

    public static void main(String[] args) {
	    new Solution();
    }

    Solution() {
        TupleList<Integer> t = readInput();
        List<Integer> s = new ArrayList<>();
        for(int i = 0; i < t.getL2().size(); i++)
            for(int j=0;j<t.getL2().get(i);j++)
                s.add(t.getL1().get(i));
        s = s.stream().sorted().collect(Collectors.toList());
        Quartiles<Integer> quartiles = new Quartiles<>(s);
        System.out.println(quartiles.getInterquartileRange());
    }

    TupleList readInput() {
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
}

class TupleList<T extends Number> {
    List<T> l1;
    List<T> l2;

    TupleList(List<T> l1, List<T> l2) {
        this.l1 = l1;
        this.l2 = l2;
    }

    public List<T> getL1() {
        return l1;
    }

    public List<T> getL2() {
        return l2;
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

    double getInterquartileRange() {
        return (getQ3() - getQ1());
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