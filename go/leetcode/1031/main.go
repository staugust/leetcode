package main

/*
https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
*/
func maxSumTwoNoOverlap(A []int, L int, M int) int {
	var sz = len(A)
	var lt = 0
	var ltm = 0
	var mt = 0
	var mtm = 0
	var mx = 0
	if L > M {
		M, L = L, M
	}
	var mtmx = make([]int, sz)
	var ltmx = make([]int, sz)
	var mtms = make([]int, sz)
	var ltms = make([]int, sz)
	for i := 0; i < sz; i++ {
		if i != 0 {
			A[i] = A[i] + A[i-1]
		}
		if i >= M-1 {
			if i >= M {
				mt = A[i] - A[i-M]
			} else {
				mt = A[i]
			}
			mtm = max(mtm, mt)
		}
		if i >= L-1 {
			lt = A[i]
			if i >= L {
				lt -= A[i-L]
			}
			ltm = max(ltm, lt)
		}
		mtms[i] = mt
		ltms[i] = lt
		mtmx[i] = mtm
		ltmx[i] = ltm
		if i >= M {
			mx = max(mx, max(mtms[i]+ltmx[i-M], ltms[i]+mtmx[i-L]))
		}
	}
	return mx
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
