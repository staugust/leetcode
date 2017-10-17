# https://leetcode.com/problems/maximum-binary-tree/description/


class TreeNode(object):
    """
    Definition for a binary tree node.
    """
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def insertIntoTree(self, root, node):
        if node.val > root.val:
            node.left = root
            return node
        else:
            cur = root
            while cur.right is not None:
                if node.val > cur.right.val:
                    node.left = cur.right
                    cur.right = node
                    return root
                cur = cur.right
            cur.right = node
            return root


    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """

        if len(nums) == 0:
            return None
        root = TreeNode(nums.pop(0))
        for v in nums:
            node = TreeNode(v)
            root = self.insertIntoTree(root, node)
        return root

if __name__ == "__main__":
    s = Solution()
    tree = s.constructMaximumBinaryTree([6,5,4,3,2,1])
    lst = [tree]
    while len(lst):
        node = lst.pop(0)

        print(node.val if node is not None else None)
        if node is not None:
            lst.append(node.left)
            lst.append(node.right)