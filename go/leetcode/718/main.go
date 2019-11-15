package main

import "fmt"

/*
https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/
var dp [1005]int

func findLength(A, B []int) (ans int) {
	if len(A) < len(B) {
		A, B = B, A
	}
	var la, lb = len(A), len(B)
	for i := lb; i > 0; i-- {
		dp[i] = 0
	}
	for i := 1; i <= la; i++ {
		for j := lb; j > 0; j-- {
			dp[j] = 0
			if A[i-1] == B[j-1] {
				dp[j] = dp[j-1] + 1
			}
			if dp[j] > ans {
				ans = dp[j]
			}
		}
	}
	return ans
}
func main() {
	A := []int{1, 2, 3, 2, 1}
	B := []int{3, 2, 1, 4, 7}
	fmt.Println(findLength(A, B))
}
