import java.util.Scanner;

public class code2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] numbers = {10, 20, 30, 40, 50};

        try {
            System.out.print("Enter an index: ");
            int i = sc.nextInt();

            System.out.println("Element at index " + i + " is: " + numbers[i]);
        } 
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array Index is not in Range");
        } 
        finally {
            sc.close();
        }
    }   
}