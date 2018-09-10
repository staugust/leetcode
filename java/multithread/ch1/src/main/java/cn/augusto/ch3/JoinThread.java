package cn.augusto.ch3;

public class JoinThread {


  public static void main(String[] args){
    Thread th1 = new Thread(){
      @Override
      public void run() {
        super.run();
        while(true){
          try {
            sleep(1000);
          } catch (InterruptedException e) {
            e.printStackTrace();
          }
          System.out.println(Thread.currentThread().getName());
        }
      }
    } ;

    th1.start();
    Thread th2 = new Thread(){
      @Override
      public void run() {
        super.run();
        try {
          sleep(1000);
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
        th1.interrupt();
      }
    };
    th2.start();
    try {
      th1.join(100000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.println("Main thread end");
  }
}
