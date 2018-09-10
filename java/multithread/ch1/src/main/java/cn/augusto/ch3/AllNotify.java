package cn.augusto.ch3;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.Random;

public class AllNotify {

  public Object obj = new Object();

  public void print() {
    synchronized (obj) {
      try {
        obj.wait();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      System.out.println(Thread.currentThread().getName() + " --> " + Calendar.getInstance().getTimeInMillis() / 1000);
    }

  }

  public static void main(String[] args) {
    AllNotify rn = new AllNotify();
    List<Thread> ths = new ArrayList<>();
    for (int i = 0; i != 100; i++) {
      Thread t1 = new Thread() {
        @Override
        public void run() {
          super.run();
          rn.print();
        }
      };
      ths.add(t1);
      t1.start();
    }
    synchronized (rn.obj) {
      rn.obj.notifyAll();
      try {
        Thread.sleep(500);
        Thread.yield();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }

    for (Thread th : ths) {
      System.out.println(th.getName() + " --> " + th.getState());
    }

  }
}
