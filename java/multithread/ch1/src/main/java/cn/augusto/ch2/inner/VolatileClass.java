package cn.augusto.ch2.inner;

public class VolatileClass implements Runnable{

  public volatile long value=MA;

  private boolean flag;

  public static long MA = 1L;
  public static long MB = 1L<<33;
  @Override
  public void run() {
    while(true){
      if(flag){
        value = MA;
      }else{
        value = MB;
      }
      flag = !flag;
    }
  }

  public static void main(String[] args){
    VolatileClass vc = new VolatileClass();
    Thread t1 = new Thread(){
      @Override
      public void run() {
        super.run();
        while(true){
          long v = vc.value;
          if(v != VolatileClass.MA && v!= VolatileClass.MB ){
            System.out.println("Not atomic");
          }
        }
      }
    };

    Thread t2 = new Thread(vc);
    t2.start();
    t1.start();
  }
}
