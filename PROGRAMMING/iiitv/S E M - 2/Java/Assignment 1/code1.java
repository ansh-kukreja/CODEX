import java.util.Scanner;

public class code1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        otherFuns f = new otherFuns();
        
        int input = -1;
        while(input != 0){
            System.out.println("\n------ Choose any Option ------");
            System.out.println("Enter 1 for Division");
            System.out.println("Enter 2 to find GCD");
            System.out.println("Enter 3 to find LCM");
            System.out.println("Enter 4 for Power");
            System.out.println("Enter 5 to find Max Value in an Array");
            System.out.println("Enter 6 to find Min Value in an Array");
            System.out.println("Enter 7 for Absolute Value");
            System.out.println("Enter 8 for Factorial");
            System.out.println("Enter 9 to find Sum of Array");
            System.out.println("Enter 10 to find Sum of Digits");
            System.out.println("Enter 11 to find Square Root");
            System.out.println("Enter 12 to check Prime");
            System.out.println("Enter 13 to check Leap Year");
            System.out.println("Enter 14 to check Palindrome");
            System.out.println("Enter 15 to check Armstrong");
            System.out.println("Enter 16 to find Arithematic Sequence Sum");
            System.out.println("Enter 17 to find Geometric Sequence Sum");

            System.out.println("Enter 0 to Exit!\n");

            System.out.println("Enter your option: ");
            input = sc.nextInt();

            switch (input) {
                case 1:
                    f.div();
                    break;
                case 2:
                    f.gcd();
                    break;
                case 3:
                    f.lcm();
                    break;
                case 4:
                    f.power();
                    break;
                case 5:
                    f.maxInArray();
                    break;
                case 6:
                    f.minInArray();
                    break;
                case 7:
                    f.abs();
                    break;
                case 8:
                    f.fact();
                    break;
                case 9:
                    f.sumOfArray();
                    break;
                case 10:
                    f.sumOfDigits();
                    break;
                case 11:
                    f.squareRoot();
                    break;
                case 12:
                    f.isPrime();
                    break;
                case 13:
                    f.isLeapYear();
                    break;
                case 14:
                    f.isPalindrome();
                    break;
                case 15:
                    f.isArmstrong();
                    break;
                case 16:
                    f.arithematicSum();
                    break;
                case 17:
                    f.geometricSum();
                    break;
                default:
                    break;
            }
        }

        sc.close();
    }
}

class otherFuns{
    int a,b,c,d,n, p;
    Scanner sc = new Scanner(System.in);

    void div(){
        System.out.println("Enter two nums to Divide: ");
        a = sc.nextInt();
        b = sc.nextInt();
        System.out.println("Division: " + (a/b));
    }
    
    void power(){
        System.out.println("Enter Number and its power: ");
        a = sc.nextInt();
        p = sc.nextInt();

        int ans = a;
        while(p > 1){
            ans *= a;
            p--;
        }
        System.out.println("Power: " + ans);
    }

    void abs(){
        System.out.println("Enter a Number: ");
        a = sc.nextInt();

        if(a < 0){
            System.out.println("Absolute value is: " + (-a));
        }
        else{
            System.out.println("Absolute value is: " + a);
        }
    }

    void fact(){
        System.out.println("Enter a Number: ");
        a = sc.nextInt();

        int ans = 1;
        while(a > 0){
            ans *= a;
            a--;
        }
        System.out.println("Factorial of " + a + " is " + ans);
    }

    void sumOfDigits(){
        System.out.println("Enter a Number: ");
        a = sc.nextInt();

        int sum = 0;
        while(a > 0){
            int digit = a%10;
            sum += digit;
            a /= 10;
        }

        System.out.println("Sum of Digits is: " + sum);
    }

    void squareRoot(){
        System.out.println("Enter a Number: ");
        a = sc.nextInt();
    
        int i = 1;
        int ans = -1;

        while (i * i <= a) {
            if (i * i == a) {
                ans = i;
            }
            i++;
        }
        
        if(ans != -1){
            System.out.println("Square Root of " + a + " is " + ans);
        }
        else{
            System.out.println("Perfect square root doesn't exists!");
        }
    }

    void gcd(){
        System.out.println("Enter two nums: ");
        a = sc.nextInt();
        b = sc.nextInt();

        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }

        System.out.println("GCD is : " + a);
    }

    void lcm(){
        System.out.println("Enter two nums: ");
        a = sc.nextInt();
        b = sc.nextInt();

        int x = a, y = b;

        while (y != 0) {
            int rem = x % y;
            x = y;
            y = rem;
        }

        int gcd = x;
        int lcm = (a / gcd) * b;

        System.out.println("LCM : " + lcm);
    }

    void isPrime(){
        System.out.println("Enter a number: ");
        a = sc.nextInt();

        if (a <= 1) {
            System.out.println("Not Prime");
            return;
        }

        boolean isPrime = true;

        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            System.out.println("Prime");
        else
            System.out.println("Not Prime");
    }

    void isLeapYear(){
        System.out.println("Enter Year: ");
        a = sc.nextInt();
        boolean isLeapYear;

        if (a % 400 == 0) isLeapYear = true;
        if (a % 100 == 0) isLeapYear = false;
        isLeapYear = ( a % 4 ) == 0;

        if(isLeapYear){
            System.out.println("It is a Leap Year");
        }
        else{
            System.out.println("Its not a Leap Year");
        }
    }

    void isPalindrome(){
        System.out.println("Enter Number: ");
        a = sc.nextInt();

        int original = a;
        int reversed = 0;

        while (a > 0) {
            int digit = a % 10;
            reversed = reversed * 10 + digit;
            a = a / 10;
        }

        if(original == reversed){
            System.out.println("It is a Palindrome Number");
        }
        else{
            System.out.println("Not a Palindrome Number");
        }
    }

    void isArmstrong(){
        System.out.println("Enter Number: ");
        a = sc.nextInt();

        int original = a;
        int sum = 0;
        int digits = 0;
        int temp = a;

        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        temp = a;

        while (temp > 0) {
            int digit = temp % 10;
            sum += Math.pow(digit, digits);
            temp /= 10;
        }

        if(sum == original){
            System.out.println("It is an Armstrong Number");
        }
        else{
            System.out.println("Not an Armstrong Number");
        }
    }

    void arithematicSum(){
        System.out.println("Enter First Term: ");
        a = sc.nextInt();
        System.out.println("Enter Common Difference: ");
        d = sc.nextInt();
        System.out.println("Enter total number of terms: ");
        n = sc.nextInt();

        int sum = (n * (2 * a + (n - 1) * d)) / 2;
    
        System.out.println("Arithematic Sequence Sum is: " + sum);
    }

    void geometricSum(){
        System.out.println("Enter First Term: ");
        a = sc.nextInt();
        System.out.println("Enter Common Ratio: ");
        b = sc.nextInt();
        System.out.println("Enter total number of terms: ");
        n = sc.nextInt();

        int sum = (int)(a * (Math.pow(b, n) - 1) / (b - 1));
        System.out.println("Geometric Sequence Sum is: " + sum);
    }

    

    void maxInArray(){
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        int maxNum = Integer.MIN_VALUE;

        System.out.println("Enter " + n + " elements: ");
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();

            if(arr[i] > maxNum){
                maxNum = arr[i];
            }
        }

        System.out.println("Maximum Number in given Array is : " + maxNum);
    }

    void minInArray(){
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        int minNum = Integer.MAX_VALUE;

        System.out.println("Enter " + n + " elements: ");
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();

            if(arr[i] < minNum){
                minNum = arr[i];
            }
        }

        System.out.println("Minimum Number in given Array is: " + minNum);
    }

    void sumOfArray(){
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        int sumArray = 0;

        System.out.println("Enter " + n + " elements: ");
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();

            sumArray += arr[i];
        }

        System.out.println("Sum of Array is: " + sumArray);
    }

}
