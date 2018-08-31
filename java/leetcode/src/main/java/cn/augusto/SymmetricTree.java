package cn.augusto;

/**
 * @Author: Augusto
 * @Description:
 * @Date: Created in 16:27 2018/8/27
 */

class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
  
  TreeNode(int x) {
    val = x;
  }
}

public class SymmetricTree {
  
  public boolean compare(TreeNode t1, TreeNode t2) {
    if (t1 == null && t2 == null) {
      return true;
    }
    if (t1 == null || t2 == null) {
      return false;
    }
    if (t1.val != t2.val) {
      return false;
    }
    return compare(t1.left, t2.right) && compare(t1.right, t2.left);
    
  }
  
  public boolean isSymmetric(TreeNode root) {
    if (root == null) {
      return true;
    }
    return compare(root.left, root.right);
  }
}
