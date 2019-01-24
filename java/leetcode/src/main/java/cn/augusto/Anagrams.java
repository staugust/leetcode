package cn.augusto;

import java.util.*;

/*
https://leetcode.com/problems/group-anagrams/description/
 */
public class Anagrams {

  public static String sort(String str) {
    char[] arr = str.toCharArray();
    Arrays.sort(arr);
    return new String(arr);
  }

  public List<List<String>> groupAnagrams(String[] strs) {
    Map<String, List<String>> map = new HashMap<String, List<String>>();
    for(String s : strs){
      String tmp = sort(s);
      if(!map.containsKey(tmp)){
        map.put(tmp, new ArrayList<String>());
      }
      map.get(tmp).add(s);
    }
    List<List<String>> res = new ArrayList<List<String>>();
    for(List<String> lst : map.values()){
      res.add(lst);
    }
    return res;
  }


  public static void main(String[] args){
    Anagrams s = new Anagrams();
    System.out.println(s.sort("abcebd"));
  }

}
