/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

func passSlice(s []int, k *int) {
	if *k >9 {
		return
	}
	tmp := *k
	if tmp >= 5 {
		s[tmp - 5] = tmp
	} else {
		s = append(s, *k)
	}
	fmt.Println("Before sub call ", tmp, cap(s) , s)
	*k += 1
	passSlice(s, k)
	fmt.Println("After sub call ", tmp, cap(s), s)
}

func main() {
	s := make([]int, 0)
	stk := 0
	fmt.Println(s, cap(s))
	passSlice(s, &stk)
	fmt.Println(s, cap(s))
}
