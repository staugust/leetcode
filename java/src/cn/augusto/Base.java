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

}


