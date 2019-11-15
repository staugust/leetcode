package main

import (
	"fmt"
)

func maximumSwap(num int) int {
	if num == 0 {
		return 0
	}
	on := num
	orig := make([]int, 0)
	for num != 0 {
		orig = append([]int{num % 10}, orig...)
		num = num / 10
	}
	for i := 0; i < len(orig); i++ {
		mx := orig[i]
		mxIdx := -1
		for j := len(orig) - 1; j > i; j-- {
			if orig[j] > mx {
				mxIdx = j
				mx = orig[j]
			}
		}
		if mxIdx != -1 {
			orig[mxIdx] = orig[i]
			orig[i] = mx
			res := 0
			for _, val := range orig {
				res = res*10 + val
			}
			return res
		}
	}
	return on
}

func main() {
	fmt.Println(maximumSwap(9973))
}
