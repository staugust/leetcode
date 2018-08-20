package cn.augusto.ch1.currentthread;

public class CountOperate extends Thread{
  public CountOperate(){
    System.out.println("CountOperate construct started");
    System.out.println("Thread.currentThread().getName() --> " + Thread.currentThread().getName());
    System.out.println("this.getName() --> " + this.getName());
    System.out.println("CountOperate construct ended");
  }

  @Override
  public void run() {
    super.run();
    System.out.println("run method started");
    System.out.println("Thread.currentThread().getName() --> " + currentThread().getName());
    System.out.println("this.getName() --> " + this.getName());
    System.out.println("run method ended");
  }

  public static void main(String[] args){
//    CountOperate c = new CountOperate();
//    Thread th = new Thread(c);
//    th.setName("AAA");
//    th.start();
    CountOperate c2 = new CountOperate();
    c2.setName("c2");
    c2.start();
  }
}
