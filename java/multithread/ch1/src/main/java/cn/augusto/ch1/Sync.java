package cn.augusto.ch1;

public class Sync extends Thread{
  @Override
  public void run() {
    super.run();
    System.out.println(Thread.currentThread().getName());
  }
  public static void main(String[] args){
    for(int i = 0; i != 10; i++){
      Sync s = new Sync();
      s.start();
    }
    System.out.println("Main thread completed.");
  }
}
