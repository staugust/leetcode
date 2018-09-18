package cn.augusto;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

/**
 * @Author: Augusto
 * @Description:
 * @Date: Created in 15:41 2018/8/27
 */
public class CombinationSumII {

  public List<List<Integer>> combinationSum2(int[] candidates, int target) {
    if (candidates.length == 0) {
      return new ArrayList<List<Integer>>();
    }
    List<List<Integer>> res = new ArrayList();
    Arrays.sort(candidates);
    Stack<Integer> stack = new Stack<Integer>();
    stack.push(candidates[0]);
    int sum = candidates[0];
    int it = 1;
    while (!stack.isEmpty()) {
      if (sum == target) {
        List lst = new ArrayList<Integer>();
        for (Integer i : stack) {
          lst.add(i);
        }
      } else if (sum < target) {
        sum += candidates[it];
        stack.push(candidates[it++]);
      } else {
        stack.pop();
        int last = stack.pop();
      }
    }
    return res;
  }
}
