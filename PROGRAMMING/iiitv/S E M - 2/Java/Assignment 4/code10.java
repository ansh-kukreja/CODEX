public class code10 {
    public static void main(String[] args) {
        Derived obj = new Derived();

        System.out.println("\n");
        obj.display();
        obj.setNumber(20);
        obj.display();
        System.out.println("\n");
    }
}


class Base {
    private int number = 10;

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }
}

class Derived extends Base {
    public void display() {
        System.out.println("Number is: " + getNumber());
    }
}