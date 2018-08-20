package main

import (
	"os"
	"bufio"
	"strconv"
	"fmt"
	"math"
)

func count(x int32) float64 {
	var i int32 = 6
	var c int32 = 1
	for ; i > x; i-- {
		c *= i
	}
	
	for i = 1; i <= (6 - x); i++ {
		c /= i
	}
	return float64(c) * math.Pow(float64(1.09/(1.09+1)), float64(x)) * math.Pow(1.00/(1.09+1), float64(6-x))
}

func test() {
	
	fmt.Printf("%.3f\n", count(6)+count(5)+count(4)+count(3))
}

func test2() {
	fmt.Printf("%.3f\n", math.Pow(0.88, 10)+math.Pow(0.88, 9)*0.12*10+math.Pow(0.88, 8)*0.12*0.12*45)
	fmt.Printf("%.3f\n", 1.0 - math.Pow(0.88, 10) - math.Pow(0.88, 9)*0.12*10 )
}

func test3() {
	
	fmt.Printf("%.3f\n", 1 - math.Pow(2.0/3.0, 5))
}


func fac(x float64) float64{
	if x == 1 || x == 0 {
		return 1.0
	}
	
	return x * fac(x -1)
}

func test4() {
	
	fmt.Printf("%.3f\n", math.Pow(2.5,5) * math.Pow(math.E, -2.5) / fac(5))
}

func test5() {
	fmt.Printf("%.3f\n", 40.0 * (0.88 * 1.88) + 160.00)
	fmt.Printf("%.3f\n", 40.0 * (1.55 * 2.55) + 128.00)
	
}


func combinationSum(candidates []int, target int) [][]int {


}

func main() {
	test5()
	test3()
	test()
	//Enter your code here. Read input from STDIN. Print output to STDOUT
	fmt.Printf("%.3f\n", 1.09*1.09*1.09/(1.09+1)/(1.09+1)/(1.09+1))
	
	var _ = strconv.Itoa // Ignore this comment. You can still use the package "strconv".
	
	var i uint64 = 4
	var d float64 = 4.0
	var s string = "HackerRank "
	
	scanner := bufio.NewScanner(os.Stdin)
	var o uint64
	var x float64
	var str string
	// Read and save an integer, double, and String to your variables.
	scanner.Scan()
	o, _ = strconv.ParseUint(scanner.Text(), 10, 64)
	scanner.Scan()
	x, _ = strconv.ParseFloat(scanner.Text(), 64)
	scanner.Scan()
	str = scanner.Text()
	o = i + o
	x = d + x
	str = s + str
	
	// Print the sum of both integer variables on a new line.
	fmt.Printf("%d\n%.1f\n%s\n", o, x, str)
}

// Complete the solve function below.
func solve(meal_cost float64, tip_percent int32, tax_percent int32) {
	fmt.Printf("The total meal cost is %d dollars.\n", int32(meal_cost*float64(tip_percent+tax_percent+100)/100.00+0.5))
	
}
