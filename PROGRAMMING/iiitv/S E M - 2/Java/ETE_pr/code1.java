
import java.io.*;

class C1 {
    int i;
    char ch;

    void set() {
        i = 20;
    }

    int get() {
        return i;
    }

    C1(int in, char c) {
        i = in;
        ch = c;
    }
}

public class code1 {
    public static void main(String[] args) {
        PrintStream printe = System.out;
        C1 obj= new C1(20,'g');
        System.out.println("i="+ obj.i);
        printe.println("ch="+ obj.ch);
    }
}