package main

import (
	"time"
	"fmt"
)

func fib(x int) int{
	if x < 2 {
		return x
	}
	return fib(x-1) + fib(x - 2)
}

func showSpin(delay time.Duration) {
	for {
		for _, r := range `-\|/`{
			fmt.Printf("\r%c", r)
			time.Sleep(delay)
		}
	}
}

func main(){
	go showSpin(100 * time.Microsecond)
	const n = 45
	fibN := fib(n)
	fmt.Printf("\r%d\n",fibN)
	fmt.Println("-----------------")
}
