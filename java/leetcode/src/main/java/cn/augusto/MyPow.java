package cn.augusto;

/*
https://leetcode.com/problems/powx-n/description/
 */
public class MyPow {
  public double myPow(double x, int n) {
    if(n == 0)
    return 1.0;
        else if(n < 0){
      if(n == Integer.MIN_VALUE)//INT_MAX = 2147483647,INT_MIN = -2147483648
        return 1.0 / (myPow(x,Integer.MAX_VALUE) * x);
      else
        return 1.0 / myPow(x,-n);
    }
    else{
      double ans = 1.0;
      while(n > 0){
        if((n & 1) == 1)//n的二进制表示中最右一位是否为1
          ans *= x;
        x *= x;
        n = n >> 1;//向右移位
      }
      return ans;
    }
  }
  public static void main(String[] args){
    MyPow mp = new MyPow();
    double x = 0.00001;
    System.out.println(mp.myPow(x, 2147483647));
  }
}
