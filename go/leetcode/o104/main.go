/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

func prev(label int) int {
	orig := label
	k := 1
	for ; label > 1; {
		label = label >> 1
		k *=2
	}
	return k - (orig - k) /2 -1
}

func pathInZigZagTree(label int) []int {
	res := make([]int, 0)
	for ; label > 0; {
		res = append([]int{label}, res...)
		label = prev(label)
	}
	return res
}

func main(){
	fmt.Println(pathInZigZagTree(26))
}