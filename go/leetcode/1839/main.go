/*
Copyright 2020 Alipay.Inc.
*/

package main

func longestBeautifulSubstring(word string) int {
	if len(word) < 5 {
		return 0
	}
	var mp = map[uint8]int{'a': 1, 'e': 2, 'i': 3, 'o': 4, 'u': 5}
	var arr = make([]int, len(word), len(word))
	if word[0] == 'a' {
		arr[0] = 1
	}
	var mx = 0
	for i := 1; i < len(word); i++ {
		if word[i] == word[i-1] || mp[word[i]] == mp[word[i-1]]+1 {
			if arr[i-1] > 0 {
				arr[i] = arr[i-1] + 1
			}
		} else {
			if word[i] == 'a' {
				arr[i] = 1
			}
		}
		if word[i] == 'u' && mx < arr[i] {
			mx = arr[i]
		}
	}
	return mx
}
