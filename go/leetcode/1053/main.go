package main

/*
https://leetcode.com/problems/previous-permutation-with-one-swap/
*/
func prevPermOpt1(A []int) []int {
	var fv int
	var fi int = -1
	var sv int = -1
	var si int = -1
	if len(A) < 2 {
		return A
	}

	for idx := 0; idx < len(A)-1; idx++ {
		if A[idx+1] < A[idx] {
			fv = A[idx]
			fi = idx
		}
	}
	if fi == -1 {
		return A
	}

	for idx := fi + 1; idx < len(A); idx++ {
		if A[idx] < fv && A[idx] > sv {
			sv = A[idx]
			si = idx
		}
	}

	A[fi], A[si] = sv, fv
	return A
}
func main() {

}
