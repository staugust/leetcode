package cn.augusto;

import java.util.ArrayList;

public class MultiplyStrings {


  public String multiply(String num1, String num2) {
    int carry = 0;
    StringBuffer sb = new StringBuffer();
    ArrayList<Integer> n1 = new ArrayList<Integer>(), n2 = new ArrayList<Integer>();
    boolean isZero = true;
    for(int i = 0; i != num1.length(); i++){
      int x = Integer.parseInt("" + num1.charAt(num1.length() - 1 - i));
      n1.add(x);
      if(x != 0) isZero = false;
    }
    if(isZero)
      return "0";
    isZero = true;
    for(int i = 0; i != num2.length(); i++){
      int y = Integer.parseInt("" + num2.charAt(num2.length() - 1 -i ));
      n2.add(y);
      if (y !=0 ) isZero = false;
    }
    if(isZero){
      return "0";
    }



    int mx = n1.size() > n2.size() ? n1.size() : n2.size();
    for(int i = 0; i != n1.size() + n2.size(); i++){
      int bitRes = carry;
      for(int j = 0; j <=i; j++){
        bitRes += (j < n1.size()? n1.get(j) : 0) * ((i-j) < n2.size() ? n2.get(i-j) : 0);
      }
      carry = bitRes / 10;
      sb.insert(0, "" + bitRes % 10);
    }
    if(carry!=0){
      sb.insert(0, "" + carry);
    }
    int it = 0;
    for(it= 0; it != sb.length(); it++){
      if(sb.charAt(it) != '0'){
        break;
      }
    }
    sb.delete(0, it);
    return sb.toString();
  }

  public static void main(String[] args) {
    MultiplyStrings m = new MultiplyStrings();
    System.out.println(m.multiply("12345", "21"));

  }
}
