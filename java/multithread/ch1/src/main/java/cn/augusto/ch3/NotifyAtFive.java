package cn.augusto.ch3;

import java.util.ArrayList;
import java.util.List;

public class NotifyAtFive {
  List<Integer> lst = new ArrayList<Integer>();

  public void add(){
    for(int i = 0; i != 10; i++){
      synchronized (lst){
        lst.add(i);
        try {
          Thread.sleep(1000);
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
        if(lst.size() == 5){
          lst.notify();
          Thread.yield();
        }
      }
    }
  }

  public static void main(String[] args){
    NotifyAtFive nf = new NotifyAtFive();
    Thread t1 = new Thread(){
      @Override
      public void run() {
        super.run();
        nf.add();
      }
    };
    t1.start();
    synchronized (nf.lst){
      try {
        nf.lst.wait();
        for(Integer i : nf.lst){
          System.out.println(i);
        }
      } catch (InterruptedException e) {
        e.printStackTrace();
      }

    }


  }
}
