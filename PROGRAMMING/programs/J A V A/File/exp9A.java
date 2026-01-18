class Animal {
    void eat() {
        System.out.println("Eating...");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("Barking...");
    }
}

// Multilevel Inheritance
class BabyDog extends Dog {
    void sleep() {
        System.out.println("Sleeping...");
    }
}

// Hierarchical Inheritance
class Cat extends Animal {
    void meow() {
        System.out.println("Meowing...");
    }
}

public class exp9A {
    public static void main(String[] args) {
        System.out.println("#### Harpreet, 2210997092, Exp9A ####");
        // Single Inheritance
        Dog dog = new Dog();
        dog.eat();
        dog.bark();

        System.out.println();

        BabyDog babyDog = new BabyDog();
        babyDog.eat();
        babyDog.bark();
        babyDog.sleep();

        System.out.println();

        Cat cat = new Cat();
        cat.eat();
        cat.meow();
    }
}
