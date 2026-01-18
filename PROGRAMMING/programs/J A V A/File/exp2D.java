import java.util.Scanner;

public class exp2D {

    public static void main(String[] args) {
        System.out.println("Gauraansh, 2210997081, Exp2D");
        Scanner scanner = new Scanner(System.in);

        // Get the number from the user
        System.out.print("Enter a number to encrypt: ");
        int number = scanner.nextInt();

        // Encrypt the number using bitwise XOR operation
        int encryptedNumber = encryptNumber(number);

        // Display the original and encrypted numbers
        System.out.println("Original number: " + number);
        System.out.println("Encrypted number: " + encryptedNumber);
    }

    // Method to encrypt a number using bitwise XOR operation
    public static int encryptNumber(int number) {
        // Hardcoded key for encryption
        int key = 123; // You can choose any key value

        // Encrypt the number using XOR operation with the key
        return number ^ key;
    }
}
