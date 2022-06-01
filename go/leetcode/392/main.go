package main

import "fmt"

func isSubsequence(s string, t string) bool {
	if len(s) == 0 {
		return true
	}
	var idx = 0
	var j = 0
	for ; j < len(s); j++ {

		for idx < len(t) {
			if t[idx] == s[j] {
				if j == len(s)-1 {
					return true
				}
				idx += 1
				break
			}
			idx += 1
		}
	}
	return false
}

func main() {
	fmt.Println(isSubsequence("b", "c"))
}
