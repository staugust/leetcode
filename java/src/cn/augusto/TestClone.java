package cn.augusto;

import java.util.concurrent.Future;

public interface TestClone extends Cloneable {

    
    
    static void main(String[] args){
        String clazzName3 = new Object(){
              public String getClassName() {
                  String clazzName = this.getClass().getName();
                  return clazzName.substring(0, clazzName.lastIndexOf('$'));
              }}.getClassName();
        System.out.println(clazzName3);
        for(String arg : args){
            System.out.println(arg);
        }
    }

}
