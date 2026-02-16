public class code6 {
    public static void main(String[] args) {
        CalculateArea ca = new CalculateArea();

        System.out.println("\nArea of Circle: " + ca.area(4));       
        System.out.println("Area of Rectangle: " + ca.area(2, 4));  
        System.out.println("Area of Triangle: " + ca.area(2f, 4f) + "\n");
    }
}

class CalculateArea{
    double area(double radius) {
        return Math.PI * radius * radius;
    }

    double area(int length, int breadth) {
        return length * breadth;
    }

    double area(float base, float height) {
        return 0.5 * base * height;
    }
}