package cn.augusto.ch1.stop;

public class StopThread extends Thread {
  @Override
  public void run() {
    try {
      super.run();
      int sum = 0;
      this.stop();
      for (int i = 0; i != 100000; i++) {
        sum += i;
      }
      System.out.println(sum);
    } catch (ThreadDeath e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    StopThread th = new StopThread();
    th.start();
  }
}
