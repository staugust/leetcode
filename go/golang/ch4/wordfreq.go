package main

import (
	"os"
	"bufio"
	"fmt"
)

func main() {
	freq := make(map[string]int)
	file, err := os.Open(os.Args[1])
	if err != nil {
		fmt.Println(err)
		os.Exit(-1)
	}
	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		word := scanner.Text()
		freq[word]++
	}
	if scanner.Err() != nil {
		fmt.Fprintln(os.Stderr, scanner.Err())
		os.Exit(1)
	}
	for word, n := range freq {
		fmt.Printf("%-30s %d\n", word, n)
	}

}
