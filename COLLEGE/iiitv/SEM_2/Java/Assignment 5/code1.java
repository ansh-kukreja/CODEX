public class code1 {
    public static void main(String[] args) {
        Student s1 = new Student("Gauraansh", 22, 39);
        s1.display();
    }
}

class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

class Student extends Person {
    int rollNum;

    Student(String name, int age, int rollNum) {
        super(name, age);
        this.rollNum = rollNum;
    }

    void display() {
        System.out.println("\n\n-- Student Details --");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Roll Number: " + rollNum + "\n\n");
    }
}