package main

import (
	"context"
	"fmt"
	"log"
	"sync"
	"time"
	"unsafe"
)

type Test struct {
	Ctx    context.Context
	Cancel context.CancelFunc
	Ticker *time.Ticker
}

func (t *Test) CheckTicker() {
	for {
		select {
		case v := <-t.Ctx.Done():
			log.Println("ok, time to stop ... ", v)
			if t.Ctx.Err() != nil {
				log.Println("ok, time to stop ... ", v)
			}
		case <-t.Ticker.C:
			log.Println("tick tick tick...")
		}
	}
}

type phase = string

func main() {
	fmt.Println(1000 / 12.000)
	//pool := sync.Pool{}
	var k int = -1
	fmt.Printf("%x\n", uint64(k)<<32)
	wg := sync.WaitGroup{}
	wg.Add(1)

	wg2 := wg
	wg2.Add(1)
	go func() {
		wg2.Done()
		time.Sleep(time.Second)
		defer func() {
			wg2.Done()
		}()
	}()
	wg2.Wait()

	fmt.Println(uintptr(unsafe.Pointer(&wg)))
	fmt.Println(uintptr(unsafe.Pointer(&wg2)))
	go func() {
		wg.Wait()
		fmt.Println("first routine wait finished")
	}()
	go func() {
		time.Sleep(time.Second)
		fmt.Println("a second later, will do Done")
		defer wg.Done()
	}()

	wg.Add(1)
	fmt.Println("main routine add 1")
	wg.Done()
	wg.Wait()
	var x phase = "abcdef"
	fmt.Println(x)
	fmt.Println(string([]byte(x)))
	fmt.Printf("%v %T\n", x, x)

	ctx, cancel := context.WithCancel(context.Background())
	ctx2, cancel2 := context.WithCancel(ctx)
	t := &Test{
		Ctx:    ctx2,
		Cancel: cancel2,
		Ticker: time.NewTicker(10 * time.Second),
	}

	go func() {
		time.Sleep(time.Second * 32)
		cancel()
	}()

	go func() {
		ch := make(chan struct{}, 100)
		close(ch)
		go func() {
			i := 1
			for {
				select {
				case v := <-ch:
					log.Printf("ch : %v\n", v)
					i += 1
					if i > 10 {
						return
					}
				}

			}

		}()

	}()

	log.Println("now ticking ...")
	go t.CheckTicker()

	time.Sleep(time.Minute)
	st := time.Now()

	fmt.Println(st.Sub(time.Now()).Nanoseconds() / 1000.000)

	log.Println("now quit ...")
}
