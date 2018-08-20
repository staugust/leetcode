package main

import "fmt"

func main() {
	var val float64
	
	for true {
		fmt.Scanf("%f\n", &val)
		fmt.Printf("%.3f\n", val+273.15)
	}
	
}
