package main

import (
	"fmt"
	"strconv"
	"strings"
)

//https://leetcode.com/problems/day-of-the-year/


func dayOfYear(date string) int {
	arrs := strings.Split(date, "-")
	Y, _ := strconv.Atoi(arrs[0])
	M, _ := strconv.Atoi(arrs[1])
	D, _ := strconv.Atoi(arrs[2])

	days := D
	FebDays := 28
	if Y%400 == 0 || (Y %4 == 0 && Y %100 != 0) {
		FebDays = 29
	}

	if M == 1 {
		return days
	}
	days += 31
	if M == 2 {
		return days
	}
	days += FebDays
	if M == 3 {
		return days
	}
	days += 31
	if M == 4 {
		return days
	}
	days += 30
	if M == 5 {
		return days
	}
	days += 31
	if M == 6 {
		return days
	}
	days += 30
	if M == 7 {
		return days
	}
	days += 31
	if M == 8 {
		return days
	}
	days +=31
	if M == 9 {
		return days
	}
	days += 30
	if M == 10 {
		return days
	}
	days += 31
	if M == 11 {
		return days
	}
	days += 30
	return days
}

func main() {
	fmt.Println(dayOfYear("2019-2-12"))
}