public class code3 {
    public static void main(String[] args) {
        Temp t1 = new Temp();

        System.out.println(t1.num);
        t1.num = 20;

        Temp t2 = new Temp();
        System.out.println(t2.num);
    }
}

class Temp{
    public static int num = 10;
}
