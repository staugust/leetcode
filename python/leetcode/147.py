# https://leetcode.com/problems/insertion-sort-list/description/



# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        root = head
        cur = head.next
        root.next = None
        while cur:
            if cur.val < root.val:
                root, cur.next, cur = cur, root, cur.next
                continue

            p = root
            flag = False
            while p.next:
                if cur.val < p.next.val:
                    nt = p.next
                    c = cur
                    cur = cur.next
                    p.next, c.next = c, nt
                    flag = True
                    break
                p = p.next
            if not flag:
                p.next = cur
                cur = cur.next
                p.next.next = None
        return root


if __name__ == '__main__':
    r = ListNode(3)
    head = r
    for i in range(5):
        if i != 3:
            node = ListNode(i)
            r.next = node
            r = node



    s = Solution()
    x = s.insertionSortList(head)
    while x:
        print(x.val)
        x = x.next