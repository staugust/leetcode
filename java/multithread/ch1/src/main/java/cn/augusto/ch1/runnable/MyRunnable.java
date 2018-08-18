package cn.augusto.ch1.runnable;

public class MyRunnable implements Runnable {
  @Override
  public void run() {
    System.out.println("Thread --> " + Thread.currentThread().getName() + " is running");
  }

  public static void main(String[] args){
    Runnable r = new MyRunnable();
    Thread th = new Thread(r);
    th.start();
    System.out.println("Main thread is completed.");
  }
}
