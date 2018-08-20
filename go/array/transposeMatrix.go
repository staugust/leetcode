package main

import (
	"fmt"
	"os"
)

func transpose(A [][]int) [][]int {
	var res [][]int
	
	for i:= 0; i != len(A[0]); i++ {
		var val []int
		for j:= 0; j != len(A); j++{
			val = append(val, A[j][i])
		}
		res = append(res, val)
	}
	return res
}


func main() {
	fmt.Println("yoyo")
	fmt.Println(os.Args)
}
