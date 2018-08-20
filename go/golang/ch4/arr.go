package main

import (
	"fmt"
	"crypto/sha256"
	"os"
	"bufio"
	"strings"
	"crypto/sha512"
)

const (
	USB = iota
	RMB
	EUR
)

var pc [256]byte

func init() {
	for i := range pc {
		pc[i] = pc[i/2] + byte(i&1)
	}
}

func count(str string) int {
	var sha = sha256.Sum256([]byte(str))
	var c = 0
	for _, val := range sha {
		c += int(pc[val])
		fmt.Printf("%#b", val)
	}
	fmt.Println("")
	return c
}

func count2(sha []byte) (x int) {
	var c = 0
	for _, val := range sha {
		c += int(pc[val])
		fmt.Printf("%#b", val)
	}
	fmt.Println("")
	return c
}

func main() {
	fmt.Println(count("你大爷"))
	var arr = [...]int{1, 2, 3}
	var arr2 = []int{1, 2}
	arr2 = append(arr2, 3)
	fmt.Println(arr)
	fmt.Println(arr2)
	fmt.Println(len(arr), cap(arr))
	fmt.Println(len(arr2), cap(arr2))
	var ar = [...]string{USB: "$", RMB: "Y", EUR: "E"}
	for _, val := range ar {
		fmt.Println(val)
	}
	
	var scan = bufio.NewScanner(os.Stdin)
	for true {
		scan.Scan()
		txt := scan.Text()
		
		if strings.Index("SHA384", txt) == 0 {
			bytes := sha512.Sum384([]byte(txt[6:]))
			var bf = make([]byte, len(bytes))
			for i, b := range bytes {
				bf[i] = b
			}
			fmt.Println(count2(bf))
		} else if strings.Index("SHA512", txt) == 0 {
			bytes := sha512.Sum512([]byte(txt[6:]))
			var bf = make([]byte, len(bytes))
			for i, b := range bytes {
				bf[i] = b
			}
			fmt.Println(count2(bf))
		} else if strings.Index("SHA256", txt) == 0 {
			bytes := sha512.Sum512_256([]byte(txt[6:]))
			var bf = make([]byte, len(bytes))
			for i, b := range bytes {
				bf[i] = b
			}
			fmt.Println(count2(bf))
		} else if txt == "q" || txt == "quit" {
			break
		} else {
			bytes := sha256.Sum256([]byte(txt))
			fmt.Println("%x", bytes)
			bytes2 := sha512.Sum512_256([]byte(txt))
			fmt.Println("%x", bytes2)
			
			var bf = make([]byte, len(bytes))
			for i, b := range bytes {
				bf[i] = b
			}
			fmt.Println(count2(bf))
			bf = make([]byte, len(bytes2))
			for i, b := range bytes2 {
				bf[i] = b
			}
			fmt.Println(count2(bf))
			
			bytes3 := sha512.Sum512([]byte(txt))
			fmt.Println("%x", bytes3)
			
			bf = make([]byte, len(bytes3))
			for i, b := range bytes3 {
				bf[i] = b
			}
			fmt.Println(count2(bf))
		}
	}
	
	var a = [5]int{1, 2, 3, 4, 5}
	reverse(&a)
	fmt.Println(a)
}

func reverse(p *[5]int) {
	for i := 0; i != len(*p)/2; i++ {
		(*p)[i], (*p)[len(*p)-1-i] = (*p)[len(*p)-1-i], (*p)[i]
	}
}
