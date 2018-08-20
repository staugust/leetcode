package cn.augusto.ch1.fj;


import java.util.Random;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.TimeUnit;

class TestRunnable implements Runnable {
  private int id = 0;

  public TestRunnable(int index) {
    super();
    id = index;
  }

  @Override
  public void run() {
    for (int i = 10; i > 0; i--) {
      System.out.println("Thread " + id + " --> is running    --->  " + i );
      try {
        Thread.sleep(1000 * i);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}

public class ForkJoinTest {
  public static void main(String[] args) {
    ForkJoinPool pool = ForkJoinPool.commonPool();
    for (int i = 0; i != 10; i++) {
      pool.execute(new TestRunnable(i));
      try {
        Thread.sleep((long)(1000 * new Random().nextDouble()));
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
    System.out.println("Main thread is completed.");
    try {
      pool.awaitTermination(1000, TimeUnit.HOURS);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }
}
