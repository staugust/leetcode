package main

import "fmt"

/*
	https://leetcode.com/problems/beautiful-arrangement-ii/
*/

func constructArray(n int, k int) []int {
	arr := make([]int, n)
	j := 0
	if k%2 == 1 {
		for i := 0; i < k/2; i++ {
			arr[j] = i + 1
			j += 1
			arr[j] = n - i
			j += 1
		}
	} else {
		for i := 0; i < k/2; i++ {
			arr[j] = n - i
			j += 1
			arr[j] = i + 1
			j += 1
		}
	}

	for i := k/2 + 1; i <= n-k/2; i++ {
		arr[j] = i
		j += 1
	}
	return arr
}

func main() {

	fmt.Println(constructArray(3, 2))

}
