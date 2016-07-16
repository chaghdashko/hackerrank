import java.util.Scanner;

public class Day112DArrays {
    public static void main(String[] args) {
        int arr[][] = new int[6][6];
        int sums[] = new int[16];
        int sumIndex = 0;

        Scanner in = new Scanner(System.in);

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                arr[i][j] = in.nextInt();
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                sums[sumIndex] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2]
                        + arr[i + 1][j + 1]
                        + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];

                sumIndex++;
            }
        }

        int max = sums[0];

        for (int i = 1; i < 16; i++) {
            if (sums[i] > max)
                max = sums[i];
        }

        System.out.println(max);
    }
}
