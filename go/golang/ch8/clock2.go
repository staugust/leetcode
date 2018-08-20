package main

import (
	"net"
	"log"
	"flag"
	"strconv"
	"io"
	"time"
)

func main() {
	port := flag.Int("port", 0, "tcp listening port")
	flag.Parse()
	lsnr, err := net.Listen("tcp", "0.0.0.0:" + strconv.Itoa(*port))
	if err != nil {
		log.Fatal(err)
	}
	
	for {
		conn, err := lsnr.Accept()
		if err != nil {
			log.Fatal(err)
			continue
		}
		go handleConn(conn)
	}
	
}

func handleConn(c net.Conn) {
	defer c.Close()
	for {
		_, err := io.WriteString(c, time.Now().Format("15:04:05\n"))
		if err != nil {
			log.Printf("%v error", c)
			return
		}
		time.Sleep(time.Second)
	}
}

