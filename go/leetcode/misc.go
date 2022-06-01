/*
Copyright 2020 Alipay.Inc.
*/

package main

import (
	"math"
	"sort"
)

func maxFrequency(nums []int, k int) int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	sum := 0
	ans := 1.0
	i := 0
	for j := 0; j < len(nums); j++ {
		sum += nums[j]
		if k+sum >= nums[j]*(j-i+1) {
			ans = math.Max(ans, float64(j-i+1))
			continue
		} else {
			for k+sum < nums[j]*(j-i+1) && i <= j {
				sum -= nums[i]
				i++
			}
		}
		if k+sum >= nums[j]*(j-i+1) {
			ans = math.Max(ans, float64(j-i+1))
		}
	}
	return int(ans)
}

/*
// it's too slow
func maxFrequency(nums []int, k int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	var mp = make(map[int]int, len(nums))
	for _, n := range nums {
		mp[n] += 1
	}
	var arr = make([]int, 0, len(mp))
	for k := range mp {
		arr = append(arr, k)
	}
	sort.Ints(arr)
	var res = make([]int, len(mp), len(mp))
	for i := range arr {
		res[i] = mp[arr[i]]
	}
	var mx = 1
	for idx := len(arr) - 1; idx >= 0; idx-- {
		var tk = k
		for j := idx - 1; j >= 0 && tk > 0 && tk >= (arr[idx]-arr[j]); j-- {
			var maxCount = tk / (arr[idx] - arr[j])
			if maxCount > mp[arr[j]] {
				maxCount = mp[arr[j]]
			}
			res[idx] += maxCount
			tk = tk - maxCount*(arr[idx]-arr[j])
		}
		if mx < res[idx] {
			mx = res[idx]
		}
	}
	return mx
}
*/

//https://leetcode.com/problems/single-threaded-cpu/
func getOrder(tasks [][]int) []int {
	if len(tasks) == 0 {
		return []int{}
	}
	for i := range tasks {
		tasks[i] = append(tasks[i], i)
	}
	sort.Slice(tasks, func(i, j int) bool {
		return tasks[i][0] < tasks[j][0]
	})
	var t = tasks[0][0]
	var result = make([]int, 0, len(tasks))
	var pickTask = func(t int) int {
		var minProcess = math.MaxInt32
		var minIdx = 0
		for i := 0; i < len(tasks) && tasks[i][0] <= t; i++ {
			if tasks[i][1] <= minProcess {
				minProcess = tasks[i][1]
				minIdx = i
			}
		}
		result = append(result, tasks[minIdx][2])
		tasks = append(tasks[:minIdx], tasks[minIdx+1:]...)
		return t + minProcess
	}
	for len(tasks) > 0 {
		t = pickTask(t)
	}
	return result
}
