/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

func corpFlightBookings2(bookings [][]int, n int) []int {
	sum := make([]int, n+1)
	for _, booking := range bookings {
		i, j, k := booking[0]-1, booking[1]-1, booking[2]
		sum[i] += k
		sum[j+1] -= k
	}

	for i := 1; i < n; i++ {
		sum[i] += sum[i-1]
	}
	return sum[:n]
}

func corpFlightBookings(bookings [][]int, n int) []int {
	var upBook = make(map[int]int)
	var downBook = make(map[int]int)
  for _, bookinfo := range bookings {
		upBook[bookinfo[0]] += bookinfo[2]
		downBook[bookinfo[1]] +=bookinfo[2]
	}

	var bookInfos = make([]int, n)
	bookInfos[0] = upBook[1]
	for i := 1; i < n; i++{
		bookInfos[i] = bookInfos[i-1]
		if val, ok := upBook[i+1]; ok {
			bookInfos[i] += val
		}
		if val, ok := downBook[i]; ok {
			bookInfos[i] -= val
		}
	}
	return bookInfos
}


func main(){
	fmt.Println(corpFlightBookings([][]int{
		{1,2,10},
		{2,3,20},
		{2,5,25},
	}, 5))
}