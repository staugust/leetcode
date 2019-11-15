package main

import "fmt"

/*
https://leetcode.com/problems/best-sightseeing-pair/
Runtime: 52 ms, faster than 90.00% of Go online submissions for Best Sightseeing Pair.
*/

func maxScoreSightseeingPair(A []int) int {
	var prev int = A[0] + 0
	var mx int
	for i := 1; i < len(A); i++ {
		if mx < A[i]-i+prev {
			mx = A[i] - i + prev
		}
		if A[i]+i-prev > 0 {
			prev = A[i] + i
		}
	}
	return mx
}

func main() {
	A := []int{1, 2, 2}
	fmt.Println(maxScoreSightseeingPair(A))

}
