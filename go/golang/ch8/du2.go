package main

import (
	"os"
	"io/ioutil"
	"fmt"
	"path/filepath"
	"flag"
	"time"
	"sync"
)

func dirents(dir string) []os.FileInfo {
	entries, err := ioutil.ReadDir(dir)
	if err != nil {
		fmt.Fprintf(os.Stderr, "du1: %v\n", err)
		return nil
	}
	return entries
}

func walkDir(dir string, n *sync.WaitGroup, fileSizes chan<- int64) {
	defer n.Done()
	for _, entry := range dirents(dir) {
		if entry.IsDir() {
			subdir := filepath.Join(dir, entry.Name())
			n.Add(1)
			go walkDir(subdir,n,  fileSizes)
		} else {
			fileSizes <- entry.Size()
		}
	}
}

var verbose = flag.Bool("v", false, "show verbose progress messages")

func main() {
	flag.Parse()
	roots := flag.Args()
	if len(roots) == 0 {
		roots = []string{"."}
	}
	fileSizes := make(chan int64)
	var n sync.WaitGroup
	
	for _, root := range roots {
		n.Add(1)
		go walkDir(root, &n,  fileSizes)
	}
	
	go func() {
		n.Wait()
		close(fileSizes)
	}()
	var tick <-chan time.Time
	if *verbose {
		tick = time.Tick(time.Millisecond * 100)
	}
	var nfiles, nbytes int64
lp:
	for {
		select {
		case size, ok := <-fileSizes:
			{
				if !ok {
					break lp
				}
				nfiles++
				nbytes += size
			}
		case <-tick:
			{
				printDiskUsage(nfiles, nbytes)
			}
		}
	}
	printDiskUsage(nfiles, nbytes)
}

func printDiskUsage(nfiles, nbytes int64) {
	fmt.Printf("%d files   %.1f GB\n", nfiles, float64(nbytes)/1e9)
}
