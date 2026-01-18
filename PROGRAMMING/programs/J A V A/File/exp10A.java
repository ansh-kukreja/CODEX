// Abstract class
abstract class Shape {
    // Abstract method
    abstract double area();
    
    // Concrete method
    void displayArea() {
        System.out.println("Area: " + area());
    }
}

// Concrete subclass
class Rectangle extends Shape {
    double length;
    double width;
    
    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    
    // Implementation of abstract method
    double area() {
        return length * width;
    }
}

public class exp10A {
    public static void main(String[] args) {
        System.out.println("--Gauraansh, 7081, Exp-10A--");
        // Cannot instantiate Shape directly, but can declare reference variables
        Shape shape1 = new Rectangle(5, 3);
        
        shape1.displayArea(); // Calls Rectangle's area() method
    }
}
