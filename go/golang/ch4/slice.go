package main

import (
	"fmt"
	"strconv"
	"unicode"
	"unicode/utf8"
)

func pr(str ...string) {
	for _,s:= range str {
		fmt.Println(string(s))
	}
}

func main() {
	//var months = []string{1: "Jan", 2: "Feb", 3: "Mar", 4: "Apr", 5: "May", 6: "Jun", 7: "Jul", 8: "Aug", 9: "Sep", 10: "Oct", 11: "Nov", 12: "Dec"}
	var months = []string{1: "Jan", 2: "Feb", 3: "Mar", 4: "Apr", 5: "May", 6: "Jun", 7: "Jul", 8: "Aug", 9: "Sep", 10: "Oct", 11: "Nov"}
	months = append(months, "Dec")
	fmt.Println(months)
	var m1 = months[:3]
	var m2 = months[3:6] //reference
	fmt.Println(m1)
	fmt.Println(m2)
	m2[0] = "March"
	fmt.Println(m1)
	fmt.Println(m2)
	m2[:7][6] = "Olala" //escape
	fmt.Println(months)
	fmt.Println(len(months), cap(months))
	fmt.Println(m2[:7])
	str := "停车坐爱枫林晚"
	fmt.Println(len(str))
	fmt.Println(str[6:12]) // as byte , not unicode
	
	for _ , v := range str {
		
		fmt.Println(string(v)) // as unicode character
		fmt.Println("" + strconv.Itoa(3333))
	}
	pr(months...)
	pr("AUB", "TEST")
	
	var arr = [5]int{}
	var slice = make([]int, 5)
	modArr(arr, 3, 3)
	modSlice(slice, 3 ,3)
	fmt.Println(arr)
	fmt.Println(slice)
	modParr(&arr, 3,3)
	fmt.Println(arr)
	var ss = []int{1,2,3,4,5,6}
	rotate(ss, 2)
	fmt.Println(ss)
	
	var sa = []string{"abc", "def","def", "c", "k", "k", "k", "u"}
	removeDup(&sa)
	fmt.Println(sa)
	
	var greetings = "你    大 爷  始 终    是   你     大    爷  停  车      坐    爱        枫      林    晚"
	//var greetings = "a b c    d  ef cg"
	var bs = keepOne([]byte(greetings))
	fmt.Printf("%s\n", bs)
	
}

func modParr( arr *[5]int, index, val int){
	(*arr)[index]=val
}
func modArr(arr [5]int, index, val int) {
	arr[index] = val
}

func modSlice(arr []int, index, val int) {
	arr[index] = val
}


func rotate(slice []int, step int) {
	tmp := make([]int, step)
	copy(tmp, slice)
	for i := step; i != len(slice); i++{
		slice[i-step] = slice[i]
	}
	for i:=0; i != len(tmp); i++ {
		slice[len(slice) -step + i] = tmp[i]
	}
}

func removeDup(sa *[]string) {
	i:=1
	for it:=1; it != len(*sa); it++ {
		if (*sa)[it] != (*sa)[it-1] {
			(*sa)[i] = (*sa)[it]
			i++
		}
	}
	*sa = (*sa)[:i]
}

func keepOne(bytes []byte) []byte {
	i:= 0
	flag := false
	for it :=0; it != len(bytes); {
		r, size := utf8.DecodeRune(bytes[it:])
		if unicode.IsSpace(r) {
			if !flag {
				for t := 0; t != size; t++ {
					bytes[i] = bytes[it]
					i++
				}
				flag = true
			}
		} else {
			for t := 0; t != size; t++ {
				bytes[i] = bytes[it]
				i++
			}
			flag = false
		}
		it+=size
	}
	return bytes[:i]
}