public class code2 {
    public static void main(String[] args) {
        Test t1 = new Test();

        t1.nonStaticMethod();
        Test.staticMethod();
    }
}

class Test{
    public static int id = 1234;
    int rollNo = 39;

    void nonStaticMethod(){
        System.out.println("\nAccessing from Non Static Method\n");
        System.out.println(id);
        System.out.println(rollNo);
    }

    static void staticMethod(){
        System.out.println("\nAccessing from Static Method\n");
        System.out.println(id);
        // System.out.println(rollNo);
    }

}
