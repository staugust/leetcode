package main

import "fmt"

/*
https://leetcode.com/problems/get-equal-substrings-within-budget/
*/

func abs(x, y uint8) int {
	if x > y {
		return int(x - y)
	}
	return int(y - x)
}

func equalSubstring(s string, t string, maxCost int) int {
	var head int = 0
	var tail int = 0
	var cost int
	var dist int
	for {
		if cost <= maxCost {
			// make tail++
			if tail < len(s) {
				cost += abs(s[tail], t[tail])
				tail += 1
				if cost <= maxCost {
					if dist < tail-head {
						dist = tail - head
					}
				}
			} else {
				if dist < tail-head {
					dist = tail - head
				}
				break
			}
		} else {
			// move head up
			for head <= tail && cost > maxCost {
				cost -= abs(s[head], t[head])
				head += 1
			}
			if dist < tail-head {
				dist = tail - head
			}
		}
	}
	return dist
}

func main() {
	var s = "abcd"
	var t = "bcdf"
	var maxCost = 3
	fmt.Println(equalSubstring(s, t, maxCost))
}
