/*i) Write a program to demonstrate the constructor overloading  
and copy constructor in java. 
ii) Create a code in which you can use all 6 constructors in a 
single call to a constructor of a class. */

public class exp8a {
	int x;
    String y;

    exp8a() {
        x = 0;
        y = "Default";
    }
    exp8a(int x) {
        this.x = x;
        y = "Parameterized Constructor 1";
    }
    exp8a(String y) {
        x = 0;
        this.y = y;
    }
    exp8a(int x, String y) {
        this.x = x;
        this.y = y;
    }
    exp8a(exp8a obj) {
        x = obj.x;
        y = obj.y;
    }
    exp8a(int x, int y) {
        this.x = x;
        this.y = "Two int parameters: " + y;
    }
    exp8a(String x, String y) {
        this.x = Integer.parseInt(x);
        this.y = y;
    }

    void display() {
        System.out.println("x = " + x + ", y = " + y);
    }
    public static void main(String args[]) {
        System.out.println("\n######## Gauraansh - 2210997081 - Exp8A ########");
    	exp8a obj1 = new exp8a();
    	exp8a obj2 = new exp8a(10);
    	exp8a obj3 = new exp8a("Hello");
    	exp8a obj4 = new exp8a(20, "World");
    	exp8a obj5 = new exp8a(obj4);
    	exp8a obj6 = new exp8a(5, 6);
    	exp8a obj7 = new exp8a("7", "Eight");
        obj1.display();
        obj2.display();
        obj3.display();
        obj4.display();
        obj5.display();
        obj6.display();
        obj7.display();
    }
}