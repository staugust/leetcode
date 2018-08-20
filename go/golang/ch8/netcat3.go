package main

import (
	"net"
	"log"
	"os"
	"io"
	"fmt"
	"time"
)

func read(x <-chan int) {
	for val := range x {
		fmt.Println("read -> ", val)
	}
}

func main() {
	var tc = make(chan int, 1)
	go read(tc)
	tc <- 1
	time.Sleep(time.Second)
	tc <- 2
	close(tc)
	conn, err := net.Dial("tcp", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}
	done := make(chan int)
	go func() {
		io.Copy(os.Stdout, conn)
		log.Println("done")
		done <- 1
	}()
	mustCopy(conn, os.Stdin)
	
	conn.(*net.TCPConn).CloseRead()
	<-done
}

func mustCopy(dst io.Writer, src io.Reader) {
	if _, err := io.Copy(dst, src); err != nil {
		log.Fatal(err)
	}
}
