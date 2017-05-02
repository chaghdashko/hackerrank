package hr.statistics;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        int[] dice1 = {1, 2, 3, 4, 5, 6};
        int[] dice2 = {1, 2, 3, 4, 5, 6};
        List<Tuple> SampleSpace = new ArrayList<>();

        for (int i = 0; i < dice1.length; i++)
            for (int j = 0; j < dice2.length; j++)
                SampleSpace.add(new Tuple(dice1[i], dice2[j]));

        List<Tuple> Event = SampleSpace.stream()
                .filter(x -> (x.getFirst() + x.getSecond()) == 6)
                .filter(x -> x.getFirst() != x.getSecond())
                .collect(Collectors.toList());

        System.out.println(Event.size() + " " + SampleSpace.size());
    }
}

class Tuple {
    int first;
    int second;

    Tuple(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public int getFirst() {
        return first;
    }

    public int getSecond() {
        return second;
    }
}