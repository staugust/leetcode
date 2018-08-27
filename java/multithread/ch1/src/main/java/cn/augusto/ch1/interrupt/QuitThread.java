package cn.augusto.ch1.interrupt;

import java.util.Random;

public class QuitThread extends Thread {
  @Override
  public void run() {
    super.run();
    for(int i = 0; i != Integer.MAX_VALUE; i++){
      System.out.println(Thread.currentThread().getName() + " --> " + i);
      try {
        sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      System.out.println(interrupted());
    }
    System.out.println("End --> " + interrupted());
  }
  public static void main(String[] args){
    QuitThread qt = new QuitThread();
    Thread th =  new Thread(qt);
    th.start();
    try {
      sleep(new Random().nextInt(2000));
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    th.interrupt();
    Thread.interrupted();
  }
}
