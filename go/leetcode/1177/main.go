package main

import (
	"fmt"
	"time"
)

/*
https://leetcode.com/problems/can-make-palindrome-from-substring/
*/

func canMakePaliQueries(s string, queries [][]int) []bool {
	res := make([]bool, len(queries))
	cache := make([]int, len(s)+1)
	var item int
	cache[0] = item
	ci := make([]int, 26)
	flag := 1
	for i := 0; i < 26; i++ {
		ci[i] = flag
		flag = flag << 1
	}

	var lastprocessed int

	for idx := 0; idx < len(queries); idx++ {
		left := queries[idx][0]
		right := queries[idx][1]
		k := queries[idx][2]
		for ; lastprocessed <= right; lastprocessed++ {
			item ^= ci[s[lastprocessed]-'a']
			cache[lastprocessed+1] = item
		}

		var tmp = cache[left] ^ cache[right+1]
		mc := 0
		for i := 0; i < 26; i++ {
			if tmp%2 == 1 {
				mc += 1
			}
			tmp = tmp / 2
		}
		res[idx] = k >= mc/2
	}
	return res
}

func main() {

	s := "hunu"
	queries := [][]int{{1, 1, 1}, {2, 3, 0}, {3, 3, 1}, {0, 3, 2}, {1, 3, 3}, {2, 3, 1}, {3, 3, 1}, {0, 3, 0}, {1, 1, 1}, {2, 3, 0}, {3, 3, 1}, {0, 3, 1}, {1, 1, 1}}
	start := time.Now()

	res := canMakePaliQueries(s, queries)
	fmt.Println("yoyo")
	fmt.Println(time.Now().Sub(start).Nanoseconds() / 1000.0000)
	fmt.Println(res)
}
