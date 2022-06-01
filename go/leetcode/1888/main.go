/*
Copyright 2020 Alipay.Inc.
*/

package main

func main() {

}

func minFlips(s string) int {
	i := len(s) % 2
	var arr = []int{0, 0}
	for ; i < len(s); i++ {
		if s[i] == '1' {
			arr[i%2] += 1
		} else {
			arr[(i+1)%2] += 1
		}
	}
	if arr[0] > arr[1] {
		return arr[1]
	}
	return arr[0]
}
