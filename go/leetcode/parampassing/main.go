package main

import "fmt"

func main() {
	arr := make([]int, 4)
	darr := make([][]int, 0)

	for i := 0; i < 10; i++ {
		arr[i%4] = i
		darr = append(darr, append([]int{}, arr...))

	}
	fmt.Println(darr)

}
