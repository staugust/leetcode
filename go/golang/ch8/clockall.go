package main

import (
	"flag"
	"net"
	"log"
	"io"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	var us, uk, cn string
	flag.StringVar(&us, "us", "localhost:8001", "us clock server addr")
	flag.StringVar(&uk, "uk", "localhost:8002", "uk clock server addr")
	flag.StringVar(&cn, "cn", "localhost:8003", "cn clock server addr")
	flag.Parse()
	
	go printClock(us)
	go printClock(uk)
	go printClock(cn)
	signalChan := make(chan os.Signal, 1)
	signal.Notify(signalChan, syscall.SIGINT, syscall.SIGTERM)
	for {
		select {
		case <-signalChan:
			log.Println("Shutdown signal received, exiting...")
			os.Exit(0)
		}
	}
}

func printClock(server string) {
	conn, err := net.Dial("tcp", server)
	if err != nil {
		log.Println(server, err)
	}
	mustCopy2(os.Stdout, conn)
	defer conn.Close()
}

func mustCopy2(dst io.Writer, src io.Reader) {
	if _, err := io.Copy(dst, src); err != nil {
		log.Fatal(err)
	}
}
