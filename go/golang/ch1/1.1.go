package main

import (
	"os"
	"fmt"
)

func main() {
	s, sep := "",""
	for _,arg := range os.Args{
		s += sep + arg
		sep = " "
	}
	fmt.Println(s)
}
