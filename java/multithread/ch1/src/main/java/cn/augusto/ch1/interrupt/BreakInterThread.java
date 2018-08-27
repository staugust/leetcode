package cn.augusto.ch1.interrupt;

public class BreakInterThread extends Thread{
  @Override
  public void run() {
    super.run();
    for(int i = 0; i != 100000; i++){
      if(interrupted()){
        System.out.println("Info "+"stopped, now break");
        break;
      }
      System.err.println(i);
    }
  }

  public static void main(String[] args){
    BreakInterThread th = new BreakInterThread();
    th.start();
    try {
      sleep(1000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    th.interrupt();

    System.out.println("Info Main thread ended.");
  }
}
