package cn.augusto.ch2.inner;

import java.util.Calendar;

public class InnerClass {
  class Inn{
    public synchronized void print(){
      System.out.println("" + this + Calendar.getInstance().getTimeInMillis()/ 1000);
      try {
        Thread.sleep(2000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      System.out.println("" + this + Calendar.getInstance().getTimeInMillis()/ 1000);
    }
  }

  public synchronized void print(){
    System.out.println("" + this + Calendar.getInstance().getTimeInMillis()/ 1000);
    try {
      Thread.sleep(2000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.println("" + this + Calendar.getInstance().getTimeInMillis()/ 1000);
  }

  public static void main(String[] args){
    InnerClass i1 = new InnerClass();
    Inn inn1 = i1.new Inn();
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
