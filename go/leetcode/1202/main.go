package main

import (
	"fmt"
	"sort"
)

/*
https://leetcode.com/problems/smallest-string-with-swaps/
*/

func findRank(arrs []int, idx int) int {
	if arrs[idx] != idx {
		arrs[idx] = findRank(arrs, arrs[idx])
	}
	return arrs[idx]
}

func smallestStringWithSwaps(s string, pairs [][]int) string {
	arrs := make([]int, len(s))
	for i := 0; i < len(arrs); i++ {
		arrs[i] = i
	}
	chs := make(map[int][]byte)
	for _, p := range pairs {
		if p[0] == p[1] {
			continue
		}
		pa, pb := findRank(arrs, p[0]), findRank(arrs, p[1])
		if pa != pb {
			arrs[pa] = pb
		}
	}

	for i := 0; i < len(arrs); i++ {
		rank := findRank(arrs, arrs[i])
		if _, ok := chs[rank]; !ok {
			chs[rank] = make([]byte, 0)
		}
		chs[rank] = append(chs[rank], s[i])
	}

	for key := range chs {
		sort.Slice(chs[key], func(i, j int) bool {
			return chs[key][i] < chs[key][j]
		})
	}

	idx := make(map[int]int)
	var str = []byte(s)
	for i := 0; i < len(s); i++ {
		r := findRank(arrs, arrs[i])
		str[i] = chs[r][idx[r]]
		idx[r] += 1
	}
	return string(str)
}

func main() {
	var s = "udyyek"

	var pairs = [][]int{{3, 3}, {3, 0}, {5, 1}, {3, 1}, {3, 4}, {3, 5}}
	//var pairs = [][]int{{0, 3}, {1, 2}}
	fmt.Println(smallestStringWithSwaps(s, pairs))
}
