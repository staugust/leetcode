# https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

import collections
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):

    def ava(self, nodes):
        """
        :type nodes: [TreeNode]
        :return: float, List[TreeNode]
        """
        res = 0
        lst = []
        for node in nodes:
            res += node.val
            if node.left is not None:
                lst.append(node.left)
            if node.right is not None:
                lst.append(node.right)
        return float(res) / len(nodes), lst


    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        if not root:
            return None
        res = []
        lst = [root]
        while len(lst) > 0:
            v, lst = self.ava(lst)
            res.append(v)
        return res

class Solution2(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        q = collections.deque()
        q.append(root)
        res = []
        while q:
            levelNum = len(q)
            sumNum = 0
            for i in range(levelNum):
                node = q.popleft()
                sumNum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res.append(sumNum / (levelNum * 1.0))
        return res

