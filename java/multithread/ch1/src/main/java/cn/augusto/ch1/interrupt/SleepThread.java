package cn.augusto.ch1.interrupt;

public class SleepThread extends Thread {
  @Override
  public void run() {
    super.run();
    try {
      sleep(100000);
      System.out.println("olaa");
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args){
    SleepThread th = new SleepThread();
    th.start();
    try {
      sleep(100);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    th.interrupt();

  }
}
