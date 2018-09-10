package cn.augusto.ch3;

import java.util.Calendar;

public class WaitNotify implements Runnable {
  public Object obj = new Object();

  @Override
  public void run() {
    try {
      System.out.println(Thread.currentThread().getName() + " --> " + Calendar.getInstance().getTimeInMillis() / 1000);
      synchronized (obj) {
        obj.wait();
      }
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.println(Thread.currentThread().getName() + " --> " + Calendar.getInstance().getTimeInMillis() / 1000);
  }

  public static void main(String[] args){
    WaitNotify wn = new WaitNotify();
    Thread t1 = new Thread(wn);
    t1.start();
    try {
      Thread.sleep(1000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    synchronized (wn.obj){
      wn.obj.notify();
    }
  }
}
