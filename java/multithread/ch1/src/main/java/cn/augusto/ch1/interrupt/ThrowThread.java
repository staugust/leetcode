package cn.augusto.ch1.interrupt;

public class ThrowThread extends Thread {
  @Override
  public void run() {
    super.run();
    try{
      for(int i = 0; i != 1000000; i++){
        if(interrupted()){
          System.out.println("Info Now stop ");
          throw new InterruptedException();
        }
        System.out.println(i);
      }
      System.out.println("Info blocks under for loop");
    }catch (InterruptedException e){
      System.out.println("Info " + "Enter into thread's catch block");
      e.printStackTrace();
    }
  }

  public static void main(String[] args){
    try{
      ThrowThread th = new ThrowThread();
      th.start();
      sleep(1000);
      th.interrupt();
    }catch (InterruptedException e){
      System.out.println("Info main catch block");
      e.printStackTrace();
    }
  }
}
