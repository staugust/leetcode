package main

import "fmt"

/*
https://leetcode.com/problems/uncrossed-lines/
find the max length of common sub sequence
*/
func maxUncrossedLines(A []int, B []int) int {
	arr := make([][]int, len(A))
	for i := 0; i < len(A); i++ {
		arr[i] = make([]int, len(B))

	}

	for i := 0; i < len(A); i++ {
		for j := 0; j < len(B); j++ {
			var last int
			var mx int
			if i != 0 && mx < arr[i-1][j] {
				mx = arr[i-1][j]
			}
			if j != 0 && mx < arr[i][j-1] {
				mx = arr[i][j-1]
			}
			if i != 0 && j != 0 {
				last = arr[i-1][j-1]
			}
			if A[i] == B[j] {
				last += 1
			}
			if mx < last {
				mx = last
			}
			arr[i][j] = mx
		}
	}
	return arr[len(A)-1][len(B)-1]
}

func main() {
	A := []int{1, 2, 4}
	B := []int{1, 4, 2}
	fmt.Println(maxUncrossedLines(A, B))
}
