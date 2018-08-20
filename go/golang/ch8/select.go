package main

import (
	"time"
	"fmt"
)

func testSelect() {
	select {}
	fmt.Println("yoyo")
}

func read(c <-chan int) {
	select {
	case x := <-c:{
		fmt.Println(x)
		
	}
	default:
		fmt.Println(time.Now().String())
	
	}
}

func main() {
	ch := make(chan int, 2)
	ch <- 3
	for i := 0; i != 10; i++ {
		go read(ch)
	}
	time.Sleep(time.Minute)
	fmt.Println(time.Now().String())
}
