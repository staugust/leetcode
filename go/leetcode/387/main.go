/*
Copyright 2020 Alipay.Inc.
*/

package main

import (
	"fmt"
	"math"
)

func firstUniqChar(s string) int {
	rec := make([]struct {
		Index int
		Count int
	}, 26)
	for idx, val := range s {
		i := val - 'a'
		if rec[i].Count == 0 {
			rec[i].Index = idx
		}
		rec[i].Count += 1
	}

	var minIdx = math.MaxInt32
	for idx := range rec {
		if rec[idx].Count == 1 {
			if rec[idx].Index < minIdx {
				minIdx = rec[idx].Index
			}
		}
	}
	if minIdx == math.MaxInt32 {
		return -1
	}
	return minIdx
}

func main() {
	fmt.Println(firstUniqChar("loveleetcode"))
}
