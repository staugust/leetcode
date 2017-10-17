# https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        lst = []
        nodeList = [root]
        while len(nodeList) != 0:
            node = nodeList.pop(0)
            if node is not None:
                nodeList.append(node.left)
                nodeList.append(node.right)
                lst.append(node.val)
        lst.sort()
        min = lst[1] - lst[0]
        for i in range(2, len(lst)):
            min = lst[i] - lst[i - 1] if min > (lst[i] - lst[i - 1]) else min
        return min

