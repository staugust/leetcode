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

var sema = make(chan struct{}, 20)
func dirents(dir string) []os.FileInfo {
	sema<- struct{}{}
	defer func() {
		<-sema
	}()
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

func printDisk(root string, fileSizes <- chan int64) {
	var nfiles , nbytes int64
	var tick  <- chan time.Time
	if *verbose {
		tick = time.Tick(time.Second)
	}
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
				fmt.Printf(root + "\t")
				printDiskUsage(nfiles, nbytes)
			}
		}
	}
	fmt.Printf(root + "\t")
	printDiskUsage(nfiles, nbytes)
}


var verbose = flag.Bool("v", false, "show verbose progress messages")

func main() {
	flag.Parse()
	roots := flag.Args()
	if len(roots) == 0 {
		roots = []string{"."}
	}
	
	var wg sync.WaitGroup
	
	for _, root := range roots {
		wg.Add(1)
		var n sync.WaitGroup
		fileSizes := make(chan int64)
		n.Add(1)
		go walkDir(root, &n,  fileSizes)
		go printDisk(root, fileSizes)
		go func(n *sync.WaitGroup, fileSizes chan int64) {
			n.Wait()
			close(fileSizes)
			defer func(){
				wg.Done()
			}()
		}(&n, fileSizes)
	}
	wg.Wait()
}

func printDiskUsage(nfiles, nbytes int64) {
	fmt.Printf("%d files   %.1f GB\n", nfiles, float64(nbytes)/1e9)
}
