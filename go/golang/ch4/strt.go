package main

import "fmt"

type Point struct {
	x, y int
}

type circle struct {
	Point  Point
	Radius int
}

type Wheel struct {
	circle
	Spokes int
}

type Object struct {
	val int
}

func (p *Object) init (){
	p.val = 5
}

func main() {
	
	var p = new(Object)
	p.init()
	fmt.Println(p.val)
	
	
	var w = Wheel{circle{Point{1, 2}, 5}, 3}
	fmt.Println(w.Point)
	fmt.Println(w.Radius)
	fmt.Println(w.circle)
	var w2 = Wheel{circle: circle{Point: Point{x: 1, y: 2}, Radius: 5}, Spokes: 3}
	fmt.Println(w2)
}
