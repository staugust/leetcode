# https://leetcode.com/problems/merge-two-binary-trees/description/

# Definition for a binary tree node.


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if t1 is None:
            t1 = t2
        else:
            t1.left = self.mergeTrees(t1.left, t2.left) if t2 is not None else t1.left
            t1.right = self.mergeTrees(t1.right, t2.right) if t2 is not None else t1.right
            t1.val = t1.val + (0 if t2 is None else t2.val)
        return t1


if __name__ == "__main__":
    s = Solution()

