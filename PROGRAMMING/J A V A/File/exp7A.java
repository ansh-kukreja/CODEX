import java.util.*;

class funds{
    Scanner sc = new Scanner(System.in);
    static int funds = 0;
    void get(){
        System.out.print("Enter your Donation Amount : ");
        int f = sc.nextInt();
        funds = funds + f;
        System.out.println("\n~~~~~~~~~~ Thanks for Donating ~~~~~~~~~~~\n");
    }
    void totalFunds(){
        System.out.println("\n\nTotal Funds Collected : "+funds);
    }
}

public class exp7A {
    static funds[] fx = new funds[4];
    public static void main(String[] args) {
        System.out.println("Gauraansh, 2210997081, Exp7A");
        for(int i = 0; i<4; i++){
            fx[i] = new funds();
            fx[i].get();
        }
        fx[0].totalFunds();
    }

}
