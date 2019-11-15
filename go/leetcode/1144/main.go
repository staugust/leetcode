/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

func movesToMakeZigzag(nums []int) int {
	var fmax , fmin = 0, 0

	// nums[0] > nums[1] && nums[2] > nums[1]
	for idx := 1; idx < len(nums); idx+=2 {
		var mn = nums[idx -1]
		if idx + 1 < len(nums) {
			if mn > nums[idx + 1]{
				mn = nums[idx+1]
			}
		}
		if nums[idx] >= mn {
			fmax += nums[idx] - mn + 1
		}
	}

	// nums[0] < nums[1] && nums[2] < nums[1]
	for idx := 0; idx < len(nums); idx+=2 {
		var mn = 0x7fffffff
		if idx > 0 {
			if mn > nums[idx - 1] {
				mn = nums[idx -1]
			}
		}
		if idx + 1 < len(nums) {
			if mn > nums[idx + 1]{
				mn = nums[idx+1]
			}
		}
		if nums[idx] >= mn {
			fmin += nums[idx] - mn + 1
		}
	}
	if fmax > fmin {
		return fmin
	}
	return fmax
}

func main() {
	arr := []int{9,6,1,6,2}
	x := movesToMakeZigzag(arr)
	fmt.Println(x)

}