package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"unicode"
	"unicode/utf8"
)

func main() {
	counts := make(map[rune]int)    // counts of Unicode characters
	mp := make(map[rune]int)
	var utflen [utf8.UTFMax + 1]int // count of lengths of UTF-8 encodings
	invalid := 0                    // count of invalid UTF-8 characters
	
	in := bufio.NewReader(os.Stdin)
	for {
		r, n, err := in.ReadRune() // returns rune, nbytes, error
		if err == io.EOF {
			break
		}
		if err != nil {
			fmt.Fprintf(os.Stderr, "charcount: %v\n", err)
			os.Exit(1)
		}
		if r == unicode.ReplacementChar && n == 1 {
			invalid++
			continue
		}
		
		if unicode.IsLetter(r) {
			if val, ok := mp[rune(97)]; !ok{
				mp[rune(97)] = 1
			} else {
				mp[rune(97)] = val + 1
			}
		} else if unicode.IsDigit(r) {
			if val, ok := mp[rune(122)]; !ok{
				mp[rune(122)] = 1
			} else {
				mp[rune(122)] = val + 1
			}
		} else {
			if val, ok := mp[rune(233)]; !ok{
				mp[rune(233)] = 1
			} else {
				mp[rune(233)] = val + 1
			}
		}
		
		counts[r]++
		utflen[n]++
	}
	fmt.Printf("rune\tcount\n")
	for c, n := range counts {
		fmt.Printf("%q\t%d\n", c, n)
	}
	fmt.Print("\nlen\tcount\n")
	for i, n := range utflen {
		if i > 0 {
			fmt.Printf("%d\t%d\n", i, n)
		}
	}
	if invalid > 0 {
		fmt.Printf("\n%d invalid UTF-8 characters\n", invalid)
	}
	
	fmt.Println("Letter\tDigit\tOthers\t")
	fmt.Println(mp[rune(97)], "\t", mp[rune(122)], "\t", mp[rune(233)])
	
}