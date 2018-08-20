package cn.augusto;

public class Chd extends Par {
    int val = 0;
    public Chd(int x){
        this.val = x;
    }
    
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return new Chd(this.val);
    }
    
    public static void main(String[] args){
        Chd c1 = new Chd(1);
        System.out.println(c1.val);
        
    }
    
}
