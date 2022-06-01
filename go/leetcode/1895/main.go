/*
Copyright 2020 Alipay.Inc.
*/

// https://leetcode.com/problems/largest-magic-square/
package main

func largestMagicSquare(grid [][]int) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	if len(grid) == 1 || len(grid[0]) == 1 {
		return 1
	}
	var m = len(grid)
	var n = len(grid[0])
	var k = 1
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			var t = getLargestMagicSquare(grid, i, j, k)
			if t > k {
				k = t
			}
		}
	}
	return k
}

func getLargestMagicSquare(grid [][]int, i, j, k int) int {
	// get largest magic square from [i,j]
	var m = len(grid) - i
	var n = len(grid[0]) - j
	if m <= k || n <= k {
		return k
	}
	var mxK = m
	if mxK > n {
		mxK = n
	}
	var tk = k + 1
	for tk <= mxK {
		// [i, j] as left-top, length is tk,
		if isSquare(grid, i, j, tk) {
			k = tk
		}
		tk += 1
	}
	return k
}

func isSquare(grid [][]int, i, j, k int) bool {
	var t1 = 0
	var t2 = 0
	for si := 0; si < k; si++ {
		t1 += grid[i+si][j+si]
		t2 += grid[i+k-1-si][j+si]
	}
	if t1 != t2 {
		return false
	}

	var target = t1

	// then check each row, each column and diagonal sum
	for ti := i; ti < i+k; ti++ {
		var ts = 0
		for tj := j; tj < j+k; tj++ {
			ts += grid[ti][tj]
		}
		if ts != target {
			return false
		}
	}

	for tj := j; tj < j+k; tj++ {
		var ts = 0
		for ti := i; ti < i+k; ti++ {
			ts += grid[ti][tj]
		}
		if ts != target {
			return false
		}
	}
	return true
}
