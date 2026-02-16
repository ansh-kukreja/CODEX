public class code5 {
    public static void main(String[] args) {
        Derived obj = new Derived(4);

        obj.display();
    }
}

class Base {
    int number;

    Base(int number) {
        this.number = number;
        System.out.println("\nBase constructor called");
    }
}

class Derived extends Base {

    Derived(int num) {
        super(num);
        System.out.println("Derived constructor called");
    }

    void display() {
        System.out.println("Value of number from Base class: " + number + "\n");
    }
}