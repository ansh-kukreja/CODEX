import java.util.Scanner;
class Interest{
	String name;
	double time;
	double rate;
	double principle;
	Interest(String n, double p, double t, double r){
		name = n;
		time = t;
		rate = r;
		principle = p;
	}
	void display() {
		double interest = (principle * time * rate) / 100;
		System.out.println("Name: " + name);
		System.out.println("Principle: " + principle);
		System.out.println("Time: " + time);
		System.out.println("Rate: " + rate);
		System.out.println("Interest: " + interest);
	}
}
public class st1prog2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

		System.out.println("Gauraansh, 2210997081, ST1:2");
        System.out.println("Enter name: ");
        String name = scanner.nextLine();

        System.out.println("Enter principle: ");
        double principle = scanner.nextDouble();

        System.out.println("Enter time: ");
        double time = scanner.nextDouble();

        System.out.println("Enter rate: ");
        double rate = scanner.nextDouble();

        Interest ob = new Interest(name, principle, time, rate);
        ob.display();
    }
}
