package cn.augusto.ch1.mutex;

import java.sql.Date;
import java.sql.Time;
import java.util.Calendar;

public class InhericLock {
  protected String key;
  public synchronized String getKey(){
    try {
      Thread.sleep(1000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    return key;
  }

  public synchronized void setKey(String k){
    try {
      Thread.sleep(1000);
    }catch (InterruptedException e){
      e.printStackTrace();
    }
    key = k;
  }

  public static void main(String[] args){
    InhericLock lock = new InhericLock();
    System.out.println(Calendar.getInstance());
    lock.setKey("Parent");
    System.out.println(Calendar.getInstance());
    lock.getKey();
    System.out.println(Calendar.getInstance());
    Child c = new Child();
    c.setKey("k");
    System.out.println(Calendar.getInstance());
    c.getKey();
    System.out.println(Calendar.getInstance());
    c.test();
    System.out.println(Calendar.getInstance());
  }
}

class Child extends InhericLock{
  public void setKey(String k){
    key = k;
  }
  public synchronized String test(){
    return super.getKey();
  }
}