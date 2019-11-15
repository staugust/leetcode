# Longest Common Subsequence 最长公共子序列

https://leetcode.com/problems/longest-common-subsequence/
## 解题思路

### 递归解法
看到题目, 首先想到的思路就是递归解法. 
1. 当两字符串的首字母相同时, 返回`longestCommonSubsequence(text1[1:],text2[1:])+1`
2. 当两字符串的首字母不相同时, 返回`max(longestCommonSubsequence(text1[1:],text2), longestCommonSubsequence(text1,text2[1:]))`

代码如下
```go

func longestCommonSubsequence(text1 string, text2 string) int {
	return lcs(text1, text2, 0, 0)
}

func lcs(s1, s2 string, idx1, idx2 int) int {
	if idx1 >= len(s1) || idx2 >= len(s2) {
		return 0
	}
    if s1[idx1] == s2[idx2] {
		return 1 + lcs(s1, s2, idx1+1, idx2+1)
	}
	p1 := lcs(s1, s2, idx1+1, idx2)
	p2 := lcs(s1, s2, idx1, idx2 + 1)
	var mx = 0
	if p1 > p2 {
		mx = p1
	}else{
		mx = p2
	}	
	return mx
}
```

提交代码运行Testcase, 通过, 说明思路没问题. 然而正式提交运行的结果是 `Time Limit Exceeded`, 说明递归的解法效率不高. 


