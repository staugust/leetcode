package main

import (
	"context"
	"fmt"
	"time"
)

func arrayNesting(nums []int) int {
	mp := make(map[int]int)
	var mx = 0
	for _, val := range nums {
		var t = 0
		_, ok := mp[val]
		for  !ok {
			t++
			mp[val] = +1
			val = nums[val]
			_, ok = mp[val]
		}
		if t > mx {
			mx = t
		}
	}
	return mx
}

func main(){
	arr := []int{5,4,0,3,1,6,2}
	fmt.Println(arrayNesting(arr))

	ctx, cancelFn := context.WithCancel(context.Background())

	k := 0
	for {
		select {
			case <-ctx.Done():
				fmt.Println("context is done")
				return
		default:
			fmt.Println("default", time.Now())
			time.Sleep(time.Second)
			k++
			if k == 4 {
				cancelFn()
			}
		}
	}
}