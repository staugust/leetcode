package cn.augusto;

import java.util.ArrayList;
import java.util.List;

public class Spiral {


  public void circle(List<Integer> lst, int[][] matrix, int l, int r, int t, int b) {
    //from lt -> rt -> rb -> lb
    for (int i = l; i < r; i++) {
      lst.add(matrix[t][i]);
    }
    for (int i = t + 1; i < b; i++) {
      lst.add(matrix[i][r - 1]);
    }
    if (b - 1 != t) {
      for (int i = r - 2; i >= l; i--) {
        lst.add(matrix[b - 1][i]);
      }
    }
    if (l != r - 1) {
      for (int i = b - 2; i > t; i--) {
        lst.add(matrix[i][l]);
      }
    }
  }

  public List<Integer> spiralOrder(int[][] matrix) {
    List<Integer> res = new ArrayList<>();
    if (matrix.length == 0) {
      return res;
    }
    int l = 0, r = matrix[0].length, t = 0, b = matrix.length;
    while (l < r && t < b)
      circle(res, matrix, l++, r--, t++, b--);
    return res;
  }


  public static void main(String[] args) {
    Spiral s = new Spiral();
    int[][] matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12},{1, 2, 3, 4},{5, 6, 7, 8}};
    List<Integer> lst = s.spiralOrder(matrix);
    System.out.println(lst);
  }

}
