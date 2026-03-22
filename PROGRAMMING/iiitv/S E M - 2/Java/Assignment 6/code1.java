import java.util.Scanner;

public class code1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter numerator: ");
            int numerator = sc.nextInt();

            System.out.print("Enter denominator: ");
            int denominator = sc.nextInt();

            int result = numerator / denominator;

            System.out.println("Result: " + result);
        } 
        catch (ArithmeticException e) {
            System.out.println("Cannot divide by zero!");
        } 
        finally {
            sc.close();
        }
    }
}
