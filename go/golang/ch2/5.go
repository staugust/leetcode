package main

import (
	"fmt"
	"math"
)

func PopCount(x uint64) int {
	i := 0
	for x != 0 {
		i++
		x = x & (x - 1)
	}
	return i
}

func main() {
	x, y := 5, 3
	fmt.Println(5 ^ 3)
	fmt.Println(x &^ y)

	var a, b, c = 0.1, -0.1, -1

	fmt.Printf("%T %T %T \n", a, b, c)

	fmt.Println(PopCount(5))
	z := 1e-4888
	fmt.Println(math.IsInf( 3 / z, 1))
	fmt.Println(3 /z )
	fmt.Println(math.IsNaN(1e-400))


	fmt.Printf("%02x", 5)

}
