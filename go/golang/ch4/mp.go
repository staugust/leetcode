package main

import "fmt"

func main() {
	
	var mp = map[string]int{}
	fmt.Println(mp == nil)
	var a ,b = 1, 2
	if a = a +b ; b == 2 {
		fmt.Println(a, b)
	}
}
