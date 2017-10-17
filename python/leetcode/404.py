# https://leetcode.com/problems/sum-of-left-leaves/description/


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def __init__(self):
        self.sum = 0
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        if root.left is not None:
            if root.left.left is None and root.left.right is None:
                self.sum += root.left.val
        self.sumOfLeftLeaves(root.left)
        self.sumOfLeftLeaves(root.right)
        return self.sum
