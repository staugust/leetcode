package cn.augusto;

public class Base< S extends Base<S>>{
    public Base( S s) {
        this.s = s;
    }
    
    public Base(){
        this.s = null;
    }
    
    public void Set(S s){
        this.s = s;
    }
    
    public void print(){
        System.out.println(this.getClass().getCanonicalName());
        if(null == s){
            System.out.println("s is null");
        }
        else {
            System.out.println(s.getClass().getCanonicalName());
        }
    }
    private S s;

    
    public static class Yo implements Runnable{
        public static Integer x = 5;
        @Override
        public void run() {
            System.out.println("start --> " + Thread.currentThread());
            synchronized (x){
                try{
                    x.wait();
                }
                catch(Exception e){
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread());
            }
            System.out.println("end --> " + Thread.currentThread());
        
        }
    }
    
    public static class Test implements Runnable{
        @Override
        public void run() {
            synchronized (Yo.x){
                Yo.x.notify();
            }
        
        }
    }
    
    public static class Test2 implements Runnable{
        @Override
        public void run() {
            synchronized (Yo.x){
                Yo.x.notifyAll();
            }
            
        }
    }
    
    public static void main(String[] args){
        for(int i = 0; i != 3; ++i){
            Thread th = new Thread(new Yo());
            th.start();
            
        }
        
        try {
            Thread.sleep(1000);
        } catch (Exception e){
            e.printStackTrace();
        }
    
        for(int i = 0; i != 30; ++i) {
            synchronized (Yo.x) {
                Yo.x.notify();
                System.out.println(new Double(System.currentTimeMillis()/ 1000.00).intValue());
                try {
                    Thread.sleep(1000);
                } catch (Exception e){
                    e.printStackTrace();
                }
            }
        }
        System.out.println("al");
        //new Thread(new Test2()).start();
        
    }
}


