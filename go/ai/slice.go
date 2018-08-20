package main

import (
	"fmt"
	"os"
)

func main() {
	var x [3]int = [3]int{1,2,3}
	var y []int = []int{1,2,3}
	fmt.Println(x)
	fmt.Printf("%T %[1]d\n", x)
	fmt.Printf("%T %[1]d\n", y)
	fmt.Print(os.Args)
}
