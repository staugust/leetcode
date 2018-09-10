package cn.augusto.ch1.sync;

import java.util.Calendar;

public class Test {
  class X{

  }
  protected String key="", val="";
  protected X x = new X();
  protected X y = new X();
  public void setKey(String k){
    synchronized (x){
      key = k;
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }

  public void setVal(String v){
    synchronized (y){
      val = v;
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }

  public String getVal(){
    synchronized (x){
      return val;
    }
  }

  public String getKey() {
    synchronized (y) {
      return key;
    }
  }

  public static void main(String[] args){
    Test t = new Test();
    t.setKey("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    Thread r = new Thread() {
      @Override
      public void run() {
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
        t.setKey("Akey");
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
        t.setVal("Aval");
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
        System.out.println(getName() + " --> " + t.getKey());
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
        System.out.println(getName() + " --> " + t.getVal());
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
      }
    };
    r.setName("ThreadA");
    Thread r2 = new Thread() {
      @Override
      public void run() {
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
        t.setKey("Bkey");
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
        t.setVal("Bval");
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
        System.out.println(getName() + " --> " + t.getKey());
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
        System.out.println(getName() + " --> " + t.getVal());
        System.out.println(getName() + " --> " + Calendar.getInstance().get(Calendar.SECOND));
      }
    };
    r2.setName("ThreadB");

    r.start();
    r2.start();

  }
}
