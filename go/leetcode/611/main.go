package main

import (
	"fmt"
	"sort"
)

/*
	https://leetcode.com/problems/valid-triangle-number/
*/

func isValid(a, b, c int) int {
	if (a+b) > c && (a+c) > b && (b+c) > a {
		return 1
	}
	return 0
}

type Cache struct {
	Value  int
	Occur  int
	Larger int
}

func triangleNumber(nums []int) int {
	sort.Ints(nums)
	cache := make([]Cache, 0)
	i := 0
	for ; i < len(nums); i++ {
		if nums[i] != 0 {
			break
		}
	}
	if len(nums) == i {
		return 0
	}
	cache = append(cache, Cache{
		Value:  nums[i],
		Occur:  1,
		Larger: len(nums) - i,
	})
	for i += 1; i < len(nums); i++ {
		if nums[i] != cache[len(cache)-1].Value {
			cache = append(cache, Cache{nums[i], 1, cache[len(cache)-1].Larger - cache[len(cache)-1].Occur})
		} else {
			cache[len(cache)-1].Occur += 1
		}
	}
	total := 0
	for idx := 0; idx < len(cache); idx++ {
		if cache[idx].Value <= 0 {
			continue
		}
		if cache[idx].Occur >= 3 {
			total += cache[idx].Occur * (cache[idx].Occur - 1) * (cache[idx].Occur - 2) / 6
		}
		if cache[idx].Occur >= 2 {
			tmp := cache[idx].Occur * (cache[idx].Occur - 1) / 2
			total += tmp * (cache[0].Larger - cache[idx].Larger)
			ub := cache[idx].Value * 2
			third := 0
			if idx+1 < len(cache) {
				third = cache[idx+1].Larger
			}
			for k := idx + 1; k < len(cache); k++ {
				if cache[k].Value >= ub {
					third = cache[idx+1].Larger - cache[k].Larger
					break
				}
			}
			total += tmp * third
		}
		for k := idx + 1; k < len(cache); k++ {
			tmp := cache[idx].Occur * cache[k].Occur
			ub := cache[idx].Value + cache[k].Value
			third := 0
			if k+1 < len(cache) {
				third = cache[k+1].Larger
			}
			for t := k + 1; t < len(cache); t++ {
				if cache[t].Value >= ub {
					third = cache[k+1].Larger - cache[t].Larger
					break
				}
			}
			total += tmp * third
		}
	}
	return total
}

func noname(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			for k := j + 1; k < len(arr); k++ {
				if isValid(arr[i], arr[j], arr[k]) == 1 {
					fmt.Println(arr[i], arr[j], arr[k])
				}
			}
		}

	}
}

func triangleNumber2(nums []int) int {
	sort.Ints(nums)
	res := 0
	for i := range nums {
		l, r := 0, i-1
		for l < r {
			if nums[l]+nums[r] > nums[i] {
				res += r - l
				r--
			} else {
				l++
			}
		}
	}
	return res
}

func main() {
	arr := []int{82, 15, 23, 82, 67, 0, 3, 92, 11}
	noname(arr)
	fmt.Println(triangleNumber(arr))

}
