package cn.augusto.ch2.inner;

import java.util.Calendar;

public class StaticClass {

  static class Inn{
    public static synchronized void print(){
      System.out.println("Inn --> " + Calendar.getInstance().getTimeInMillis()/ 1000);
      try {
        Thread.sleep(2000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      System.out.println("Inn --> " + Calendar.getInstance().getTimeInMillis()/ 1000);
    }
  }

  public static synchronized void print(){
    System.out.println("Out --> " + Calendar.getInstance().getTimeInMillis()/ 1000);
    try {
      Thread.sleep(2000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.println("Out --> " + Calendar.getInstance().getTimeInMillis()/ 1000);
  }

  public static void main(String[] args){
    StaticClass i1 = new StaticClass();
    StaticClass.Inn inn1 = new StaticClass.Inn();
    Thread th1 = new Thread() {
      @Override
      public void run() {
        super.run();
        i1.print();
      }
    };

    Thread th2 = new Thread() {
      @Override
      public void run() {
        super.run();
        inn1.print();
      }
    };
    th1.start();
    th2.start();

  }

}
