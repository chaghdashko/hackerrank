import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Day28Regex {
    public static void main(String[] args) {
        String s = "\b[A-Z0-9._%+-]+@gmail.com\b";
        Pattern p = Pattern.compile(s);
        
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.next());
        
        List<String> names = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            String address = scanner.next();
            
            if (address.endsWith("@gmail.com")) {
                names.add(name);
            }
            
            names.sort((a, b) -> a.compareTo(b));
        }
        
        for (String name : names) {
            System.out.println(name);
        }
    }
}