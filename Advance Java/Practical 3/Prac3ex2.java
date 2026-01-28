class threadRunnable implements Runnable {

    int threadNum;

    threadRunnable(int num) {
        this.threadNum = num;
    }

    public void run() {
        for(int i = 0; i < 5; i++) {
            System.out.println("Thread running " + threadNum + " " + i);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

public class Prac3ex2 {
    public static void main(String[] args) {
        threadRunnable r1 = new threadRunnable(1);
        threadRunnable r2 = new threadRunnable(2);
        threadRunnable r3 = new threadRunnable(3);

        Thread t1 = new Thread(r1);
        Thread t2 = new Thread(r2);
        Thread t3 = new Thread(r3);

        t1.start();
        t2.start();
        t3.start();
    }
}
