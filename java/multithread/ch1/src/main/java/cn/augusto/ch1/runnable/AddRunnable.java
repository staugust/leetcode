package cn.augusto.ch1.runnable;

public class AddRunnable implements Runnable {
  int count = 0;
  public AddRunnable(int val){
    super();
    count = val;
  }
  @Override
  public void run() {
    super.toString();
    while(count-->0) {
      System.out.println(Thread.currentThread().getName() + " --> " + count);
    }
  }

  public static void main(String[] args){
    Runnable r = new AddRunnable(4);
    for(int i= 0; i != 4; i++){
      new Thread(r).start();
    }
    System.out.println("Main thread completed.");
  }

}
