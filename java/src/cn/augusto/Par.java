package cn.augusto;

public class Par<T extends Par> {
    
    public Par(){
    
    }
    
    public T cl(){
        try { return (T)super.clone(); }
        catch( CloneNotSupportedException e ) { e.printStackTrace(); throw new RuntimeException(e);}
    }
    
}
