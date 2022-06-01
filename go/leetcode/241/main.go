/*
Copyright 2020 Alipay.Inc.
*/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

/*
 * see https://leetcode.com/problems/different-ways-to-add-parentheses/
 */
func diffWaysToCompute(input string) []int {
	numStr := strings.Fields(strings.ReplaceAll(strings.ReplaceAll(strings.ReplaceAll(input, "+", " "), "-", " "), "*", " "))
	numbers := make([]int, 0)
	for _, v := range numStr {
		n, _ := strconv.Atoi(v)
		numbers = append(numbers, n)
	}
	if len(numbers) == 0 {
		return []int{}
	}
	dp := make([][][]int, len(numbers))
	for i := range dp {
		dp[i] = make([][]int, len(numbers))
	}
	for i := range dp {
		dp[i][i] = []int{numbers[i]}
	}
	sign := make([]rune, 0, len(numbers)-1)
	for _, v := range input {
		switch v {
		case '+', '-', '*':
			sign = append(sign, v)
		}
	}
	return calc(numbers, sign, dp, 0, len(numbers)-1)
}

func calc(numbers []int, sign []rune, dp [][][]int, i, j int) []int {
	if len(dp[i][j]) != 0 {
		return dp[i][j]
	}
	for m := i; m < j; m++ {
		a := calc(numbers, sign, dp, i, m)
		b := calc(numbers, sign, dp, m+1, j)
		for _, va := range a {
			for _, vb := range b {

				switch sign[m] {
				case '+':
					dp[i][j] = append(dp[i][j], va+vb)
				case '-':
					dp[i][j] = append(dp[i][j], va-vb)
				case '*':
					dp[i][j] = append(dp[i][j], va*vb)
				}
			}
		}
	}
	return dp[i][j]
}

func main() {
	fmt.Println(diffWaysToCompute("2*3-4*5"))
}
