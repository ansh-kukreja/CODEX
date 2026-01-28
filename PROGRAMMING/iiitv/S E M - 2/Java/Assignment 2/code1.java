import java.util.Scanner;

public class code1 {
    public static void main(String[] args) {
        Employee[] emp = new Employee[20];

        System.out.println("\n-- Enter Details of Employee 1 --\n");
        emp[0] = new Employee();
        emp[0].inputAddress();
        emp[0].inputPosition();
        // emp[0].showPrivate();

        System.out.println("\n-- Enter Details of Employee 2 --\n");
        emp[1] = new Employee(39, "Gauraansh");
        emp[1].inputAddress();
        emp[1].inputPosition();
        // emp[1].showPrivate();

        System.out.println("\n");
        emp[0].show();
        emp[1].show();
        System.out.println("\n");
    }
}

class Employee{
    private int id;
    public String name;
    public String address;
    public String position;

    Scanner sc = new Scanner(System.in);

    Employee() {
        System.out.print("Enter Employee Id: ");
        id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Employee Name: ");
        name = sc.nextLine();
    }

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public void inputAddress() {
        System.out.print("Enter Address: ");
        address = sc.nextLine();
    }

    public void inputPosition() {
        System.out.print("Enter Position in Company: ");
        position = sc.nextLine();
    }

    public void show() {
        System.out.println("\n-- Employee Details --");
        System.out.println("Id: " + id);
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Position: " + position);
    }

    private void showPrivate() {
        System.out.println("Id: " + id);
    }
}