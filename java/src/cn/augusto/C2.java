package cn.augusto;

public class C2 extends Par<C2> {
    int x = 0;
    public C2(int z){
        this.x= z;
    }
    
    public static void main(String[] args){
        Par<Chd> c = new Par();
        Chd c2 = c.cl();
        System.out.println(c2.val);
    }
    
}
