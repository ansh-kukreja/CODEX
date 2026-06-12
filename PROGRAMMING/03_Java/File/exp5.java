import java.util.*;
public class exp5 {

    static int ar[]=new int[400],n;
    static Scanner s1=new Scanner(System.in);

    static void get() {
        System.out.println("Enter Numbers of elements ");
        n=s1.nextInt();
        System.out.println("Enter numbers");
        for(int i=150; i<=150+n; i++) {
            ar[i]=s1.nextInt(); 
        }
    }
    static void display() {
        for(int i=150; i<150+n; i++) {
            System.out.println(" "+ar[i]);
        }
    }
    
    static void query1(){
        System.out.println("---orginal array---");
        for(int i=150; i<=150+n; i++) {
            System.out.println(" "+ar[i] );
        }
        for(int i=150; i<=150+n; i++) {
            boolean b1=check(i);
            if (b1) {
                ar[i]=i;
            }
        }
        System.out.println("\n---modified array---");
        for(int i=150; i<=150+n; i++){
            System.out.println(" "+ar[i]);
        }
    }
    static boolean check(int k) {
        int temp=k;
        int n=0;
        while (temp>0) {
            int r=temp%10;
            n+=r*r*r;
            temp=temp/10;
        }
        if (n==k) {
            return true;
        }
        else{
            return false;
        }
    }
    static void query2() {
        int temp;
        System.out.println("Enter the number whose multiple is to be deleted");
        temp=s1.nextInt();
        for(int i=150; i<150+n; i++) {
            if (ar[i]%temp==0) {
                delete(i);
                i--;
            }
        }
    }
    static void delete(int index) {
        for(int i=index; i<150+n; i++) {
            if (i==150+n-1) break;
            ar[i]=ar[i+1]; {
                n=n-1;
            }
        }
    }
    static void query3() {
        int largest=ar[150], smallest=ar[150],sum;
        for(int i=151; i<150+n; i++) {
            if (largest<ar[i]) {
                largest=ar[i];
            }
            if (smallest>ar[i]) {
                smallest=ar[i];
            }
        }
        sum=largest+smallest;
        int mid=152;
        for(int i=150+n-1; i>=mid; i--) {
            ar[i+1]=ar[i];
        }
        ar[mid]=sum;
        n=n+1;
    }
    static void query4() {
        int j=150, i;
        for(i=150+n;; i++) {
            ar[i]=ar[j];
            j++;
            if (j==150+n) break;
        }
        for(int k=150; k<150+n; k++) {
            ar[k]=ar[i];
            i--;
        }
    }
    public static void main(String[] args) {
        System.out.println("Gauraansh, 2210997081, Exp5");
        int ch;
        while (true) {
            System.out.println("Enter the option \n1. Replace the values\n2. Delete the mulriple of a number \n3. Insert the sum of largest and smallest \n4. Reverse the array");
            ch=s1.nextInt();
            switch (ch) {
                case 1:
                    get();
                    query1();
                    break;
                case 2:
                    get();
                    query2();
                    break;
                case 3:
                    get();
                    query3();
                    break;
                case 4:
                    get();
                    query4();
                    break;
                default:
            }
            System.out.println("\nwant to continue Y for yes and N for no");
            char c=s1.next().charAt(0);
            if (c=='n') break; {
                
            }
        }
    }
}