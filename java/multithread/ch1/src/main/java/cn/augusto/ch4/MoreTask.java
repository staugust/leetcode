package cn.augusto.ch4;

import sun.util.resources.cldr.ga.CalendarData_ga_IE;

import java.util.Calendar;
import java.util.Timer;
import java.util.TimerTask;

public class MoreTask extends TimerTask {
  @Override
  public void run() {
    System.out.println(Thread.currentThread().getName() + " --> " + Calendar.getInstance().getTimeInMillis() );
    try {
      Thread.sleep(2000);
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    //System.out.println(Thread.currentThread().getName() + " --> " + Calendar.getInstance().getTimeInMillis() );
  }

  public static void main(String[] args){
    Timer t = new Timer();
    TimerTask tt = new MoreTask();
    Thread th = new Thread(){
      @Override
      public void run() {
        super.run();
        t.scheduleAtFixedRate(tt, 1000, 3000);
      }
    };
    th.setDaemon(false);
    th.start();

    try {
      Thread.sleep(1000 * 11);]' '
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    System.out.println(th.getState());
    //tt.cancel();
  }
}
