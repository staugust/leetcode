package cn.augusto;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
https://leetcode.com/problems/permutations/description/
 */
public class Permutations {

  public List<List<Integer>> permute(int[] nums) {
    ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
    if (nums.length == 0) {
      return res;
    } else if (nums.length == 1) {
      ArrayList<Integer> lst = new ArrayList<Integer>();
      lst.add(nums[0]);
      res.add(lst);
      return res;
    } else {
      for (int i = 0; i != nums.length; i++) {
        int[] tArr = new int[nums.length - 1];
        for (int j = 0, z = 0; j != nums.length; j++) {
          if (i != j) {
            tArr[z++] = nums[j];
          }
        }
        List<List<Integer>> rr = permute(tArr);
        for (List<Integer> lst : rr) {
          lst.add(nums[i]);
          res.add(lst);
        }
      }
      return res;
    }

  }


  public List<List<Integer>> permuteUnique(int[] nums) {
    ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
    Set<Integer> set = new HashSet<Integer>();
    if (nums.length == 0) {
      return res;
    } else if (nums.length == 1) {
      ArrayList<Integer> lst = new ArrayList<Integer>();
      lst.add(nums[0]);
      res.add(lst);
      return res;
    } else {
      for (int i = 0; i != nums.length; i++) {
        if(set.contains(nums[i])) {
          continue;
        }
        set.add(nums[i]);
        int[] tArr = new int[nums.length - 1];
        for (int j = 0, z = 0; j != nums.length; j++) {
          if (i != j) {
            tArr[z++] = nums[j];
          }
        }
        List<List<Integer>> rr = permuteUnique(tArr);
        for (List<Integer> lst : rr) {
          lst.add(nums[i]);
          res.add(lst);
        }
      }
      return res;
    }
  }



  public static void main(String[] args) {
    Permutations p = new Permutations();
    int[] arr = {1,2,2,3};
    List<List<Integer>> res = p.permuteUnique(arr);
    System.out.println(res.size());
    System.out.println(res);
  }
}
