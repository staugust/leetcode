package cn.augusto;

import java.util.Scanner;

/**
 * @Author: Augusto
 * @Description:
 * @Date: Created in 16:17 2018/8/27
 */
public class Sqrt {
  public int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
  
    int lo = 0, hi = x;
  
    while (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
    
      if (mid > x / mid) hi = mid;
      else lo = mid;
    }
  
    return hi > x / hi ? lo : hi;
  }
  public static void main(String[] args){
    Sqrt s = new Sqrt();
    Scanner scan = new Scanner(System.in);
    while(scan.hasNext()){
      System.out.println(s.mySqrt(scan.nextInt()));
    }
  }
  
}
