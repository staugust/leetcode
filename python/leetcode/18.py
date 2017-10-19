# https://leetcode.com/problems/4sum/description/

class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        mp = {}
        res = []
        for i in range(len(nums) -1):
            for j in range(i+1,len(nums)):
                key = nums[i] + nums[j]
                if key not in mp:
                    mp[key] = []
                mp[key].append([i,j])
        scanned = set()
        for key in mp.keys():
            if target - key in mp and target - key not in scanned:
                fl = mp[key]
                ll = mp[target - key]
                for a in fl:
                    for b in ll:
                        if b[0] not in a and b[1] not in a:
                            lt = list()
                            lt.append(nums[a[0]])
                            lt.append(nums[a[1]])
                            lt.append(nums[b[0]])
                            lt.append(nums[b[1]])
                            lt.sort()
                            if res.count(lt) == 0:
                                res.append(lt)
                scanned.add(key)
                scanned.add(target - key)
        return res




if __name__ == "__main__":
    s = Solution()
    print(s.fourSum([i for i in range(10)],18))
