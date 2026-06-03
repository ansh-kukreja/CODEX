public class code4 {
    static {
        System.out.println("\nFirst Static block executed.");
    }

    public static void main(String[] args) {
        System.out.println("Main method executed.\n");
    }

    static {
        System.out.println("Second static block executed.");
    }
}