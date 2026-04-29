import java.util.ArrayList;
import java.util.Scanner;

public class code2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> lines = new ArrayList<>();

        System.out.println("Enter 'stop' to end: ");

        while (true) {
            String input = sc.nextLine();
            if(input.equalsIgnoreCase("stop")) {
                break;
            }
            lines.add(input);
        }

        System.out.println("\nInput Lines: ");

        for (String line : lines) {
            System.out.println(line);
        }

        sc.close();
    }
}
