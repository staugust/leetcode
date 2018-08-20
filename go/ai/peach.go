package main

import (
	"fmt"
	"sort"
)

func longestValidParentheses(s string) int {
	var h, t , sum = 0,0,0
	var mx = -1
	for it, c := range s {
		if c == '(' {
			sum += 1
		} else {
			sum -= 1
			if sum == 0 {
				t = it
				if mx < (t - h)  {
					mx = t - h
				}
			} else if sum < 0 {
				for h < it {
				
				}
				
				
			} else {
			
			}
			
			
		}
		
	}
	return 0
}

func next(cans []int, cur int) int {
	for it, val := range cans {
		if val == cur && it+1 < len(cans) {
			return cans[it+1]
		}
	}
	return -1
}

func combinationSum(candidates []int, target int) [][]int {
	var res [][]int
	if len(candidates) == 0 {
		return res
	}
	sort.Ints(candidates)
	var stack []int
	var sum = candidates[0]
	stack = append(stack, candidates[0])
	
	for len(stack) > 0 {
		if sum < target {
			stack = append(stack, stack[len(stack)-1])
			sum += stack[len(stack)-1]
		} else {
			
			if sum == target {
				var lst = make([]int, len(stack))
				copy(lst, stack)
				res = append(res, lst)
			}
			
			if len(stack) <= 1 {
				break
			}
			
			var nt = 0
			if stack[len(stack)-2 ] == candidates[len(candidates)-1] {
				var it = len(stack) - 2
				for it > -1 {
					if stack[it] != candidates[len(candidates) - 1]{
						break
					}
					it--
				}
				if it != -1 {
					nt = next(candidates, stack[it])
					stack = stack[0:it]
					stack = append(stack, nt)
					sum = 0
					for _, val := range stack {
						sum += val
					}
				} else {
					break
				}
				
			} else {
				sum -= stack[len(stack)-2]
				sum -= stack[len(stack)-1]
				nt = next(candidates, stack[len(stack)-2])
				stack = stack[0 : len(stack)-2]
				sum += nt
				stack = append(stack, nt)
			}
		}
	}
	return res
}

func main() {
	longestValidParentheses("abcde")
	
	var tt = []int{2, 3, 5}
	fmt.Print(combinationSum(tt, 8))
	var N int
	fmt.Scanf("%d\n", &N)
	var x int
	var y int
	var c uint8
	var sx int
	var sy int
	fmt.Scanf("%d %d\n", &sx, &sy)
	for i := 0; i != N*N; i++ {
		fmt.Scanf("%c", &c)
		if c == 'p' {
			x = i / N
			y = i % N
		}
		if (i+1)%N == 0 {
			fmt.Scanf("\n")
		}
		
	}
	if sx > x {
		for i := x; i != sx; i++ {
			fmt.Printf("UP\n")
		}
	} else if sx < x {
		for i := x; i != sx; i-- {
			fmt.Printf("DOWN\n")
		}
	} else {
	}
	
	if sy > y {
		for i := y; i != sy; i++ {
			fmt.Printf("LEFT\n")
		}
	} else if sy < y {
		for i := y; i != sy; i-- {
			fmt.Printf("LEFT\n")
		}
	} else {
	}
	
}
