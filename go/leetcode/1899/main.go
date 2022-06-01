/*
Copyright 2020 Alipay.Inc.
*/

// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

package main

func main() {

}

func mergeTriplets(triplets [][]int, target []int) bool {
	x, y, z := target[0], target[1], target[2]

	var fx, fy, fz = false, false, false
	for _, item := range triplets {
		if item[0] <= x && item[1] <= y && item[2] <= z {
			if fx || item[0] == x {
				fx = true
			}
			if fy || item[1] == y {
				fy = true
			}
			if fz || item[2] == z {
				fz = true
			}
		}
		if fx && fy && fz {
			return true
		}
	}
	return fx && fy && fz
}
