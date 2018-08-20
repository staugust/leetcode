package main

import (
	"fmt"
	"unicode/utf8"
	"bytes"
	"sort"
)

func comma(s string) string {
	var bf bytes.Buffer
	var str = []byte(s)
	var index = len(str)
	for i, b := range str {
		if b == '.' {
			index = i
		}
	}
	for i := range str {
		fmt.Println(str[i])
		bf.WriteByte(str[i])
		if (index - i - 1)%3 == 0  && i < index-2{
			bf.WriteByte(',')
		}
	}
	return bf.String()
}

type IntSlice []int32
func (c IntSlice) Len() int {
	return len(c)
}
func (c IntSlice) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
}
func (c IntSlice) Less(i, j int) bool {
	return c[i] < c[j]
}


func compareStr(s1, s2 string) bool {
	var arr1, arr2 IntSlice
	for _, v := range s1 {
		arr1 = append(arr1, v)
	}
	
	for _, v := range s2 {
		arr2 = append(arr2, v)
	}
	
	sort.Sort(arr1)
	sort.Sort(arr2)
	
	for i := 0 ;i != len(arr1); i++ {
		if arr1[i] != arr2[i] {
			return false
		}
	}
	
	return true
}

func main() {
	
	
	fmt.Println(compareStr("你大爷是谁", "谁是你大爷"))
	var s = "+12345678.12312312"
	// range string with unicode , treat each unicode rune, not byte
	for _,v := range s {
		fmt.Println(v)
	}
	fmt.Println(len(s))
	fmt.Println(utf8.RuneCountInString(s))
	fmt.Println(comma(s))
}
