public class code4 {
    public static void main(String[] args) {
        MyThread t = new MyThread();
        t.start();
        System.out.println("Main thread");
    }
}

class MyThread extends Thread{
    public void run(){
        System.out.println("Thread running");
    }
}