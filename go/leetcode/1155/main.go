package main

import "fmt"

//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

const MODULAR int = 1E9 + 7
func numRollsToTarget(d int, f int, target int) int {
	prev := make([]int, target + 1)
	cur := make([]int, target + 1)
	for i := 1; i <= f && i <= target; i++{
		cur[i] = 1
	}
	for j := 2; j <= d; j++ {
		prev, cur = cur, make([]int, target + 1)
		for t := j ; t <= target && t <= j * f; t++ {
			val := 0
			for v := t  -1 ; v >= t-f && v > 0 ; v-- {
				val += prev[v]
				val = val % MODULAR
			}
			cur[t] = val
		}
	}
	return cur[target]
}

func test() *int {
	return new(int)
}

func main(){
	var x int = 5
	&x = test()
	fmt.Println(x)


	fmt.Println(numRollsToTarget(3,6,18))
	//fmt.Println(numRollsToTarget(2,6,7))
	//fmt.Println(numRollsToTarget(2,5,10))
	//fmt.Println(numRollsToTarget(1,2,3))
	fmt.Println(numRollsToTarget(30,30, 500))
	fmt.Printf("%d\n", MODULAR)


}

