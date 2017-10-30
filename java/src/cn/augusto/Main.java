package cn.augusto;
import java.lang.Thread;

class TestThread extends Thread{
    public TestThread(int s){
        this.sec = s;
    }
    private int sec;
    @Override
    public void run() {
        for(int i = 0; i != sec; ++i){
            try {
                Thread.sleep(1000);
                System.out.println(Thread.currentThread().getId());
                
            }catch (Exception e){
                e.printStackTrace();
            }
        }
    }
}


class Tick implements Runnable{
    public Tick(int s){
        sec = s;
    }
    private int sec = 0;
    @Override
    public void run(){
        for(int i = 0; i != sec; ++i){
            try {
                Thread.sleep(1000);
                System.out.println(Thread.currentThread().getId());
            
            }catch (Exception e){
                e.printStackTrace();
            }
        }
    }
    
}

public class Main {

    public static void main(String[] args) {
	// write your code here
        Base<Task> b = new Base<Task>();
        
        Task s = new Task();
        s.Set(s);
        
        b.print();
        s.print();
        System.out.println(Void.class.getCanonicalName());
        
        TestThread t1 = new TestThread(5);
        TestThread t2 = new TestThread(10);
        t1.start();
        t2.start();
        try {
            t2.join();
            System.out.println("Thread t2 is done.");
            t1.join();
            System.out.println("Thread t1 is done.");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        Thread th1 = new Thread(new Tick(5));
        Thread th2 = new Thread(new Tick(10));
        th1.start();
        th2.start();
        try {
            th2.join();
            System.out.println("Thread th2 is done.");
            th1.join();
            System.out.println("Thread th1 is done.");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
    
    
    }
}
