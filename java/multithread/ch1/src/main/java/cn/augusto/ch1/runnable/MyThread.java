package cn.augusto.ch1.runnable;

import java.util.Calendar;

public class MyThread extends Thread {
  public MyThread(String name) {
    super();
    setName(name);
  }

  @Override
  public void run() {
    super.run();
    while (count-- > 0) {
      System.out.println(Thread.currentThread().getName() + " --> " + count);
      try {
        sleep(count * 1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      System.out.println("Thread count -> " + Thread.activeCount());
    }
  }

  public static void main(String[] args) {
    System.out.println(Thread.activeCount());
    MyThread a = new MyThread("A");
    MyThread b = new MyThread("B");
    MyThread c = new MyThread("C");
    a.start();
    b.start();
    c.start();
    System.out.println("Main thread completed.");
    System.out.println(Calendar.getInstance());
  }

  private int count = 5;
}
