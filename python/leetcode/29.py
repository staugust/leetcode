# https://leetcode.com/problems/divide-two-integers/description/
class Solution(object):
    def divide(self, dividend, divisor):
        if divisor == 0:
            return -1
        positive = (dividend < 0) is (divisor < 0)
        dividend, divisor = abs(dividend), abs(divisor)
        res = 0
        while dividend >= divisor:
            temp, i = divisor, 1
            while dividend >= temp:
                dividend -= temp
                res += i
                i <<= 1
                temp <<= 1
                print(temp,i,res)
        if not positive:
            res = -res
        return min(max(-2147483648, res), 2147483647)

if __name__ == '__main__':
    s = Solution()
    s.divide(9,1)