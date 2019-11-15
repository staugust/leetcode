package main

func subarraySum(nums []int, k int) int {
	var sum = 0
	var arr = make([]int, len(nums) + 1)
	for i := 0; i < len(nums); i++{
		arr[i+1] = arr[i] + nums[i]
	}
	for i:= 0 ; i < len(arr); i++{
		for j:= i+1; j < len(arr); j++{
			if arr[j] - arr[i] == k {
				sum += 1
			}
		}
	}
	return sum
}

//using map to check
func subarraySum2(nums []int, k int) int {
	count := 0
	m := make(map[int]int)
	prefixSum := 0

	for _, num := range nums{
		prefixSum += num

		// prefixSum <= sum
		if prefixSum == k{
			count++
		}

		// prefixSum > sum
		if _, ok := m[prefixSum-k]; ok{
			count += m[prefixSum-k]
		}

		m[prefixSum]++
	}
	return count
}