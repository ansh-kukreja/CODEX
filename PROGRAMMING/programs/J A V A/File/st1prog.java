import java.util.*;
public class st1prog {
    public static void main(String[] args) {
        System.out.println("Gauraansh, 2210997081, ST1:1");
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Year of Birth : ");
        int year = sc.nextInt();
        int sum = year;
        int firstSum = 0;
        while(sum>0){
            firstSum += sum%10;
            sum /= 10;
        }
        System.out.println("Sum of 4 digits = " + firstSum);
        int secondSum = 0;
        while(firstSum > 0){
            secondSum += firstSum % 10;
            firstSum /= 10;
        }
        System.out.print("Sum of 4 digits "+secondSum);
    }
}
