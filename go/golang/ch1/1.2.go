package main

import (
	"os"
	"fmt"
)

func main() {
	for it,arg := range os.Args[1:]{
		fmt.Println(it, arg)
	}
}
