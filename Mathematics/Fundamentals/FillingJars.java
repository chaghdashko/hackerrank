import java.io.*;
import java.util.*;

public class FillingJars {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();
        
        long total = 0;
        
        for (int i = 0; i < m; i++) {
            long a = scanner.nextLong();
            long b = scanner.nextLong();
            long k = scanner.nextLong();
            
            total = total + (k * (b - a + 1));
        }
        
        System.out.println(total / n);
    }
}