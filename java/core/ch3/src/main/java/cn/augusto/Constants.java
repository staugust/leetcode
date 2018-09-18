package cn.augusto;

public class Constants {
  class Test{
  }
  public String s;
  public int x;
  public long l;
  public short sh;
  public byte b;
  public boolean bl;
  public char c;
  public float f;
  public double d;
  public Test t;
  public static void main(String[] args) {
    final double CM_PER_INCH = 2.54;
    double paperWidth = 8.5;
    double paperHeight = 11;
    System.out.println("Paper size in centimeters: "
                           + paperWidth * CM_PER_INCH + " by " + paperHeight * CM_PER_INCH);

    Constants c = new Constants();
    System.out.println(c.t);
    System.out.println(c.s);
    System.out.println(c.b);
    System.out.println(c.sh);
    System.out.println(c.x);
    System.out.println(c.l);
    System.out.println(c.c);
    System.out.println(c.bl);
    System.out.println(c.f);
    System.out.println(c.d);
    int tmp = 0;
    System.out.println(tmp);
  }
}
