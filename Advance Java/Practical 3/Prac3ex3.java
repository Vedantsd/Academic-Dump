import java.util.concurrent.*;

class MyTask implements Runnable {
    int num;

    MyTask(int num) {
        this.num = num;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Thread running " + num + " " + i);
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

public class Prac3ex3 {
    public static void main(String[] args) {

        ThreadGroup group = new ThreadGroup("Group 1");

        Thread t1 = new Thread(group, new MyTask(1));
        Thread t2 = new Thread(group, new MyTask(2));
        Thread t3 = new Thread(group, new MyTask(3));

        t1.setPriority(1);
        t2.setPriority(5);
        t3.setPriority(10);

        t1.start();
        t2.start();
        t3.start();

        ExecutorService pool = Executors.newFixedThreadPool(3);

        pool.execute(new MyTask(4));
        pool.execute(new MyTask(5));
        pool.execute(new MyTask(6));

        pool.shutdown();

        System.out.println("\nThread Group Name: " + group.getName());
        System.out.println("Active Threads: " + group.activeCount());
    }
}
