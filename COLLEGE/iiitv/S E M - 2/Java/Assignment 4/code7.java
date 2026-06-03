public class code7 {
    public static void main(String[] args) {
        if(args.length == 0){
            System.out.println("No command line arguments given");
            return;
        }

        System.out.println("\nCommand Line Arguments are -\n");

        for(int i = 0; i < args.length; i++){
            System.out.println(args[i]);
        }
        System.out.println("\n");
    }
}


// javac code7.java
// java code7 Gauraansh 20251651039