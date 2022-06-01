/*
Copyright 2020 Alipay.Inc.
*/

package main

func chalkReplacer(chalk []int, k int) int {
	var total = 0
	for i := range chalk {
		total += chalk[i]
		k -= chalk[i]
		if k < 0 {
			return i
		}
	}
	k = k % total
	for i := range chalk {
		k -= chalk[i]
		if k < 0 {
			return i
		}
	}
	return 0
}
