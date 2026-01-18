// Parent class
class Animal {
    void speak() {
        System.out.println("Animal Sound");
    }
}

// Child class 1
class Dog extends Animal {
    @Override
    void speak() {
        System.out.println("barks");
    }
}

// Child class 2
class Cat extends Animal {
    @Override
    void speak() {
        System.out.println("meows");
    }
}

public class exp9B {
    public static void main(String[] args) {
        System.out.println("\n---- Gauraansh, 2210997081, Exp9B ----\n");
        // Creating objects of the child classes
        Animal animal1 = new Dog();
        Animal animal2 = new Cat();

        // Dynamic method dispatch
        animal1.speak(); // Output will be "Dog barks"
        animal2.speak(); // Output will be "Cat meows"
    }
}
