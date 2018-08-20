package main

import "fmt"

func main() {
	var ia [0]int
	var sa [0]string
	
	var i2 [0]int
	fmt.Println(sa)
	
	
	
	
	fmt.Println( &ia == &i2)
	
	var i3 [2]int
	var i4 [2]int
	fmt.Println( &i3 == &i4)
	
	var p1 = new([0]int)
	var p2 = new([0]int)
	fmt.Println(p1 == p2)
	
	
}
