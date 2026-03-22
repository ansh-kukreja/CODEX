import java.util.Scanner;

public class code3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Circle c = new Circle();

        try {
            System.out.print("Enter radius: ");
            double r = input.nextDouble();

            c.setRadius(r);

            System.out.println("Radius set successfully");
        } 
        catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        } 
        finally {
            input.close();
        }
    }
}

class Circle {
    private double radius;

    public void setRadius(double r) {
        if (r < 0) {
            throw new IllegalArgumentException("Radius cannot be negative");
        }
        radius = r;
    }
}