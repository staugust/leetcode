package main

import (
	"net"
	"bufio"
	"time"
	"fmt"
	"strings"
	"log"
)

func main() {
	lsnr, err := net.Listen("tcp", "0.0.0.0:8000")
	if err != nil {
		log.Fatal(err)
	}
	
	for {
		conn, err := lsnr.Accept()
		if err != nil {
			log.Fatal(err)
			continue
		}
		handleConn(conn)
	}
}

func echo(c net.Conn, shout string, delay  time.Duration) {
	fmt.Fprintln(c, "\t", strings.ToUpper(shout))
	time.Sleep(time.Second)
	fmt.Fprintln(c, "\t", shout)
	time.Sleep(time.Second)
	fmt.Fprintln(c, "\t", strings.ToLower(shout))
}

func handleConn(c net.Conn){
	input := bufio.NewScanner(c)
	for input.Scan() {
		go echo(c, input.Text(), time.Second)
	}
	c.Close()
}