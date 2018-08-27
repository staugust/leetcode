package cn.augusto.ch1.interrupt;

import cn.augusto.ch1.runnable.MyThread;

import java.util.Random;

public class InterruptThread extends Thread {
  @Override
  public void run() {
    super.run();
    for(int i= 0; i != 100000; i++) {
      System.err.println("i = " + i);

    }
  }

  public static void main(String[] args){
    InterruptThread th = new InterruptThread();
    th.start();
    try {
      sleep(1000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    th.interrupt();
    System.out.println("Is stopped 1 --> " + th.isInterrupted());
    System.out.println("Is stopped 2 --> " + th.isInterrupted());

    System.out.println("Is stopped 1 --> " + interrupted());
    System.out.println("Is stopped 2 --> " + interrupted());

  }
}
