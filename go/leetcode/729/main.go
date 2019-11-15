package main

import "fmt"

type MyCalendar struct {
	Books [][]int
}

func Constructor() MyCalendar {
	return MyCalendar{
		Books: make([][]int, 0),
	}
}

func (this *MyCalendar) Book(start int, end int) bool {
	if len(this.Books) == 0 {
		this.Books = append(this.Books, []int{start, end})
		return true
	}
	idx := 0
	for idx = range this.Books {
		if this.Books[idx][0] == start {
			return false
		}
		if this.Books[idx][0] > start {

			if this.Books[idx][0] < end {
				return false
			}
			if idx != 0 {
				if this.Books[idx-1][1] > start {
					return false
				}
			}
			this.Books = append(this.Books[:idx], append([][]int{[]int{start, end}}, this.Books[idx:]...)...)
			return true
		}
	}
	if this.Books[idx][1] > start {
		return false
	} else {
		this.Books = append(this.Books, []int{start, end})
		return true
	}
}

func main() {
	cal := Constructor()
	fmt.Println(cal.Book(47, 50))
	fmt.Println(cal.Book(33, 41))
	fmt.Println(cal.Book(20, 30))
}
