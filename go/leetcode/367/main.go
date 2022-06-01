/*
Copyright 2020 Alipay.Inc.
*/

package main

func isPerfectSquare(num int) bool {
	for i := 0; i <= num; i++ {
		if i*i == num {
			return true
		} else if i*i > num {
			break
		}
	}
	return false
}

func main() {

}
