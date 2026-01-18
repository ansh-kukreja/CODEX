// Interface 1
interface Vehicle {
    void start();
    void stop();
}

// Interface 2
interface ElectricVehicle {
    void charge();
}

// Class implementing both interfaces
class ElectricCar implements Vehicle, ElectricVehicle {
    public void start() {
        System.out.println("Electric car started.");
    }
    
    public void stop() {
        System.out.println("Electric car stopped.");
    }
    
    public void charge() {
        System.out.println("Electric car charging.");
    }
    
    public void drive() {
        System.out.println("Electric car driving.");
    }
}

public class exp10B {
    public static void main(String[] args) {
        System.out.println("\n--Gauraansh, 7081, Exp-10B--\n");
        ElectricCar tesla = new ElectricCar();
        
        // Using methods from both interfaces
        tesla.start();
        tesla.drive();
        tesla.charge();
        tesla.stop();
    }
}
