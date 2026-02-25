public class code2 {
    public static void main(String[] args) {
        Dog d = new Dog();
        d.sound();
        d.getPrivate();
    }
}

class Animal {
    private String type = "Animal";

    void sound() {
        System.out.println("Animals Sounds");
    }
}

class Dog extends Animal {
    void sound() {
        System.out.println("\nDog barks\n");
    }

    void getPrivate(){
        // System.out.println(type);
    }
}