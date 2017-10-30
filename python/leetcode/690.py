# https://leetcode.com/problems/employee-importance/description/

"""
# Employee info
"""
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates

class Solution(object):
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        mp = {}
        for emp in employees:
            mp[emp.id] = emp

        s = mp[id].importance
        x = mp[id].subordinates
        while x:
            em = mp[x.pop()]
            s += em.importance
            x = x + em.subordinates

        return s
