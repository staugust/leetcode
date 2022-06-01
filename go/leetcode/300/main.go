/*
Copyright 2020 Alipay.Inc.
*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	arr := []int{10, 9, 2, 5, 3, 7, 101, 18}
	fmt.Println(lengthOfLIS(arr))

	root := &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val:  3,
			Left: nil,
			Right: &TreeNode{
				Val:   2,
				Left:  nil,
				Right: nil,
			},
		},
		Right: nil,
	}
	recoverTree(root)
}

// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3808/
func lengthOfLIS(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	res := make([]int, len(nums))
	mp := make(map[int]int, len(nums))
	mp[0] = nums[0]

	for i := 1; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				if res[i] < res[j]+1 {
					res[i] = res[j] + 1
				}
			}
		}
	}
	mx := res[0]
	for i := 1; i < len(nums); i++ {
		if mx < res[i] {
			mx = res[i]
		}
	}
	return mx + 1
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// https://leetcode.com/problems/recover-binary-search-tree/
func recoverTree(root *TreeNode) {
	arr := make([]*TreeNode, 0)
	recoverTreeToArr(root, &arr)

	dst := make([]int, len(arr))
	for i := range arr {
		dst[i] = arr[i].Val
	}
	sort.Ints(dst)

	for i := range arr {
		arr[i].Val = dst[i]
	}
}

func recoverTreeToArr(root *TreeNode, arr *[]*TreeNode) {
	if root.Left != nil {
		recoverTreeToArr(root.Left, arr)
	}
	*arr = append(*arr, root)
	if root.Right != nil {
		recoverTreeToArr(root.Right, arr)
	}
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}
