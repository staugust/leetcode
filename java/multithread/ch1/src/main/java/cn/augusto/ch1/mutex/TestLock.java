package cn.augusto.ch1.mutex;


import cn.augusto.ch1.Test;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantLock;

public class TestLock extends Thread {

  private Lock lock = new ReentrantLock();
  private String key="k", val="v";
  @Override
  public void run() {
    super.run();
    lock.lock();
    val = "ahaha";
    try {
      sleep(5000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    Integer.parseInt("al");

  }

  public synchronized void setKey(String k){
    lock.lock();
    key = k;
    lock.unlock();
  }

  public String getKey(){
    return key;
  }

  public String getVal(){
    String v = "";
    lock.lock();
    v = val;
    lock.unlock();
    return v;
  }

  public static void main(String[] args){
    TestLock t = new TestLock();
    t.start();
    try {
      sleep(1000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    //t.interrupt();
    t.setKey("safsa");
    System.out.println(t.getKey() + "  -->  " + t.getVal());
  }
}
