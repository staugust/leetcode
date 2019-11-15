package main

import "fmt"

/*
https://leetcode.com/problems/grumpy-bookstore-owner/
*/
func maxSatisfied(customers []int, grumpy []int, X int) int {
	gain := 0
	satis := 0
	mxgain := 0
	idx := 0
	for idx = 0; idx < X && idx < len(customers); idx++ {
		satis += customers[idx] * (1 - grumpy[idx])
		gain += customers[idx] * grumpy[idx]
	}
	if idx == len(customers) {
		return satis + gain
	}
	mxgain = gain
	for idx = X; idx < len(customers); idx++ {
		satis += customers[idx] * (1 - grumpy[idx])
		var ng = customers[idx]*grumpy[idx] - customers[idx-X]*grumpy[idx-X]
		gain += ng
		if gain > mxgain {
			mxgain = gain
		}
	}
	return satis + mxgain
}

func main() {

	cust := []int{4, 10, 10}
	grumpy := []int{1, 1, 0}
	X := 2
	fmt.Println(maxSatisfied(cust, grumpy, X))

}
