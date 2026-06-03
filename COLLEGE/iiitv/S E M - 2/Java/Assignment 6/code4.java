
public class code4 {
    public static void main(String[] args) {
        Mammal m1 = new Dog();
        Mammal m2 = new Human();

        m1.sound();
        m2.sound();
    }
}


abstract class Mammal {
    abstract void sound();
}

class Dog extends Mammal {
    void sound() {
        System.out.println("Dog barks");
    }
}

class Human extends Mammal {
    void sound() {
        System.out.println("Hello World!");
    }
}