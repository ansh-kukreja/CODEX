
public class code2 {
    public static void main(String[] args) {
        Employee[] emp = new Employee[20];

        emp[0] = new Employee(001, "Gauraansh", "CS");
        emp[1] = new Employee(002, "Ansh", "Sales");
        emp[2] = new Employee(003, "Tony", "Marketing");

        Manager m = new Manager();
        m.check(emp, 3, 002);
        System.out.println("\n");
    }
}

class Manager{

    public void check(Employee[] emp, int n, int searchId){
        // System.out.println(emp[0].id);

        boolean found = false;
        for(int i=0; i<n; i++){
            if (emp[i].pId == searchId) {
                System.out.println("\nEmployee Found!");
                details(emp[i]);
                found = true;
                break;
            } 
        }
        if(!found){
            System.out.println("Employee Not Found!");
        }
    }

    public void details(Employee emp){
        System.out.println("\n-- Employee Details --");
        emp.show();
    }
}

class Employee{
    private int id;
    public int pId;
    public String name;
    public String department;

    Employee(int id, String name, String department) {
        this.pId = id;
        this.name = name;
        this.department = department;
    }

    void show() {
        System.out.println("ID: " + pId);
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);
    }
}