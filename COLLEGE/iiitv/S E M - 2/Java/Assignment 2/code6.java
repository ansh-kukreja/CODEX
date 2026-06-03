import java.util.Scanner;

public class code6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter String: ");
        String a = sc.nextLine();

        System.out.print("Enter Substring: ");
        String b = sc.nextLine();

        if(a.contains(b)) {
            System.out.println(b + " is a substring of " + a + "\n");
        } 
        else {
            System.out.println(b + " is NOT a substring of " + a + "\n");
        }

        sc.close();
    }
}
