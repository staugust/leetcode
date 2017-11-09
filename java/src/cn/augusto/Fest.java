package cn.augusto;


import java.net.Socket;
import java.nio.channels.ByteChannel;
import java.util.concurrent.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

public class Fest {
    public enum Ft{
        Zhongqiu(8,15),
        Duanwu(5,5),
        Chunjie(1,1),
        Zhongyuan(7,15),
        Chongyang(9,9);
        
        final int mon;
        final int day;
        Ft(int m, int d){mon = m; day = d;}
        void print(){
            System.out.println("" + this.mon + " -> " + this.day);
        }
    }
    
    public static class MyTask extends CountedCompleter<MyTask>{
        final int s;
        final int t;
        public Integer sum;
        final static int THRES = 100;
        public MyTask(int x, int y){
            s = x;
            t = y;
            sum = 0;
        }
        
        public MyTask(CountedCompleter<?> comp, int x ,int y, Integer ss){
            super(comp);
            s = x;
            t = y;
            sum = ss;
        }
        
        @Override
        public void compute() {
            System.out.println("" + s + " -> " + t);
            if(Math.abs(s - t) > THRES){
                new MyTask(this, s,  s + THRES, sum).fork();
                new MyTask(this, s + THRES, t, sum).fork();
            }
            else{
                int tmp = 0;
                for(int i = s; i < t; ++i){
                    tmp += i;
                }
                
                CountedCompleter<?> caller = this;
                while( (caller = caller.getCompleter()) != null && caller.getCompleter() != null){
                
                }
                synchronized (((MyTask)caller).sum){
                    ((MyTask)caller).sum += tmp;
                }
                System.out.println("sum is " + ((MyTask)caller).sum);
            }
            tryComplete();
        }
    
        @Override
        public void onCompletion(CountedCompleter<?> caller) {
            super.onCompletion(caller);
        }
    }
    
    
    
    
    public static void main(String[] args) throws InterruptedException {
        for(Fest.Ft f : Fest.Ft.values()){
            System.out.println(f.name() + " -> " + f.ordinal());
            f.print();
        }
        ByteChannel[] _socks = new ByteChannel[2];
        System.out.println(_socks.length);
        ConcurrentMap<Integer, String> mp = new ConcurrentHashMap<>();
        ForkJoinPool pool = new ForkJoinPool(2);
        MyTask tk = new MyTask(1,2001);
        pool.submit(tk);
        while(!tk.isDone()){
            try{
                Thread.sleep(1000);
            }
            catch (Exception e){
                e.printStackTrace();
            }
        }
        System.out.println(tk.sum);
    }
}
