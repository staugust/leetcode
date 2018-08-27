package cn.augusto.ch1.pause;

public class PauseThread extends Thread {
  @Override
  public void run() {
    super.run();
    for(int i = 0 ; i< 100000; i++){
      System.err.println(i);
    }
  }

  public static void main(String[] args){
    PauseThread th = new PauseThread();
    th.start();
    try {
      sleep(100);
      th.suspend();
      sleep(3000);
      th.resume();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }
}
