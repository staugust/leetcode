package main

import (
	"math/rand"
	"fmt"
	"strings"
	"time"
)

/*
	test two methond on string concat.
 */

const SEED int64 = 0xFF
const STRLEN int = 5

func randStr() string {
	var str string
	for i := 0; i < STRLEN; i++ {
		c := rand.Uint32()%26 + 'A'
		str += string(c)
	}
	return str
}

func main() {
	rand.Seed(SEED)
	const maxLoop = 100000
	var strLst []string
	for i := 0; i < maxLoop; i++ {
		strLst = append(strLst, randStr())
	}

	var s1, s2, sep string
	var st1, et1, st2, et2 int64
	st1 = time.Now().UTC().UnixNano()
	for _, s := range strLst {
		s1 += sep + s
		sep = " "
	}
	et1 = time.Now().UTC().UnixNano()
	fmt.Println("loop costs --> ", et1-st1)
	fmt.Println(s1[0])
	st2 = time.Now().UTC().UnixNano()
	s2 = strings.Join(strLst, " ")
	et2 = time.Now().UTC().UnixNano()
	fmt.Println("join costs --> ", et2-st2)
	fmt.Println(s2[0])

}
