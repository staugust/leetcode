package cn.augusto.ch1.sync;

import java.util.Calendar;

public class SyncClass {
  public static synchronized void print(){
    System.out.println("print --> " + Calendar.getInstance().getTimeInMillis()/ 1000);
    try {
      Thread.sleep(1000*3);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.println("print --> " + Calendar.getInstance().getTimeInMillis()/ 1000);
  }


  public static void main(String[] args){
    Thread th = new Thread(){
      @Override
      public void run(){
        System.out.println(getName() + " --> " + Calendar.getInstance().getTimeInMillis() / 1000);
        synchronized (SyncClass.class){
          try {
            sleep(1000 * 3);
          } catch (InterruptedException e) {
            e.printStackTrace();
          }
        }
        System.out.println(getName() + " --> " + Calendar.getInstance().getTimeInMillis() / 1000);
      }
    };

    Thread th2 = new Thread() {
      @Override
      public void run() {
        super.run();
        SyncClass.print();
      }
    };
    th.start();
    th2.start();
  }
}
