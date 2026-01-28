import java.lang.*;

class thread extends Thread {
    int threadNum;

    thread(int id) {
        this.threadNum = id;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Thread running " + threadNum + " " + i);
            try {
                thread.sleep(1000);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }

        System.out.println("Thread id = " + getId());
        System.out.println("Priority = " + getPriority());
        System.out.println("is Alive = " + isAlive());
        System.out.println("Name = " + getName());
    }
}

public class Prac3ex1 {
    public static void main(String[] args) {
        thread t1 = new thread(1);
        thread t2 = new thread(2);

        t2.setPriority(Thread.MAX_PRIORITY);
        t1.setPriority(Thread.MIN_PRIORITY);

        t1.start();
        t2.start();
    }
}
