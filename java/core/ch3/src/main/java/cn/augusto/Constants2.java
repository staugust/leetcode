package cn.augusto;

public class Constants2 {
  static final double CM_PER_INCH = 2.54;

  public static void main(String[] args) {
    double paperWidth = 8.5;
    double paperHeight = 11;
    System.out.println("Paper size in centimeters: "
                           + paperWidth * CM_PER_INCH + " by " + paperHeight * CM_PER_INCH);

    String s1="", s2 = "";
    for(int i= 0 ;i != 3; i++){
      s1 += "a";
      s2 += "a";
    }
    //s2 = "aaa aaa aaa aaa aaa ";
    System.out.println(s1 == s2);
    System.out.println(s1 == s2.intern());
    System.out.println(s1.intern() == s2.intern());
  }
}