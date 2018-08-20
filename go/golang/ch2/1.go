package main

import "fmt"

var x  = 5

func incr(p * int ) int{
	*p++
	return *p
}

func main() {
	var nb []byte
	var xx []string
	if nb == nil {
		println("nil")
	}

	if nil == xx{
		println("nil []string")
	}

	println(x)

	fmt.Println(nb)


	y := incr(&x)
	if &x != &y {
		fmt.Println("not equal ")
	}
	fmt.Println("%d %d\n", x, y)
	y = incr(&y)
	fmt.Println("%d %d\n", x, y)
}

var a = b + c
var b = f()
var c = 1
func f() int {
	return 2
}