package main

func findDuplicates(nums []int) []int {
	abs := func(k int) int {
		if k < 0{
			return -k
		}
		return k
	}
	res := make([]int, 0)
	for i := 0; i < len(nums); i++{
		if nums[abs(nums[i]) - 1] < 0 {
			res = append(res, abs(nums[i]))
		}else {
			nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1]
		}
	}
	return res
}
