package cn.augusto.ch1.currentthread;

public class AliveThread extends Thread {
  @Override
  public void run() {
    super.run();
    for (int i = 0; i != 10; i++) {
      System.out.println(Thread.currentThread().getName() + "  -->  " + this.isAlive());
      try {
        sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }

  public static void main(String[] args){
    AliveThread a = new AliveThread();
    a.start();
    for(int i = 20; i > 0; i--){
      System.out.println(Thread.currentThread().getName() + "  -->  " + a.isAlive());
      try {
        sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}
