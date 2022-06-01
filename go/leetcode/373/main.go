/*
Copyright 2020 Alipay.Inc.
*/

/*
 * see https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 */

package main

import "fmt"

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	if len(nums1) == 0 || len(nums2) == 0 {
		return [][]int{}
	}

	res := make([][]int, 0)
	var i = 1
	var j = 1
	for {
		if i*j >= k {
			break
		}
		if i >= len(nums1) {
			if j >= len(nums2) {
				break
			}
			j++
			continue
		}
		if j >= len(nums2) {
			if i >= len(nums1) {
				break
			}
			i++
			continue
		}
		if nums1[i] < nums2[j] {
			i += 1
		} else {
			j += 1
		}
	}
	i = i - 1
	j = j - 1
	for a := 0; a < i; a++ {
		for b := 0; b < j; b++ {
			res = append(res, []int{nums1[a], nums2[b]})
		}
	}

	var x = 0
	var y = 0
	for x <= j && y <= i {
		if (nums1[i] + nums2[x]) < (nums1[y] + nums2[j]) {
			res = append(res, []int{nums1[i], nums2[x]})
			x += 1
		} else {
			res = append(res, []int{nums1[y], nums2[j]})
			y += 1
		}
		if len(res) == k {
			break
		}
	}
	return res
}

func main() {
	var a = []int{1, 2, 4, 5, 6}
	var b = []int{3, 5, 7, 9}
	var k = 3
	fmt.Println(kSmallestPairs(a, b, k))
}
