package main

import "fmt"

func maxProfit(prices []int, fee int) int {
	if len(prices) < 2 {
		return 0
	}

	ans := 0
	min := prices[0]

	for i := 1; i < len(prices); i++ {
		// 1
		if prices[i] < min {
			min = prices[i]
		} else {
			if prices[i] > min+fee {
				// 4
				ans += prices[i] - fee - min
				// 5
				min = prices[i] - fee
			}
		}
	}
	return ans
}

type Phase int

const TestPhase Phase = 1

func (phase Phase) String() string {
	return fmt.Sprintf("Phase %d", phase)
}

func main() {
	fmt.Printf("%s\n", TestPhase)
	arr := []int{1, 3, 2, 8, 4, 9}
	fee := 2
	fmt.Println(maxProfit(arr, fee))
}
