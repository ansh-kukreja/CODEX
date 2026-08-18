import java.util.Scanner;

public class code3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter First String: ");
        String s1 = sc.nextLine();

        System.out.print("Enter Second String: ");
        String s2 = sc.nextLine();

        if (s1.equals(s2)) {
            System.out.println("\nBoth Strings are Equal!\n");
        } 
        else {
            System.out.println("\nStrings are Not Equal!\n");
        }

        sc.close();
    }
}
