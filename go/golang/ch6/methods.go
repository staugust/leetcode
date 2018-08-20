package main

import (
	"fmt"
	"bytes"
	"strconv"
)

type Point struct {
	x, y int
}

func (p Point) SetX(x int) {
	p.x = x
}

func (p Point) SetY(y int) Point {
	var tmp =Point{p.x, p.y}
	tmp.y = y
	return tmp
}

func (p Point) Print() {
	fmt.Printf("Point x -> %d, y -> %d\n", p.x, p.y)
	fmt.Printf("%d\n", &p)
}


func (p Point) String() string {
	var buf bytes.Buffer
	buf.WriteString("Point -->  \n")
	buf.WriteString("  x -> " + strconv.Itoa(p.x) + "\n")
	buf.WriteString("  y -> " + strconv.Itoa(p.y) + "\n")
	return buf.String()
}

func main() {
	var p = Point{1,2}
	fmt.Println(p)
	p.Print()
	p.SetX(3)
	p.Print()
	var q = p.SetY(4)
	q.Print()
}

