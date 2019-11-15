/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

func duplicateZeros(arr []int)  {
	n := len(arr)
	if n == 0 {
		return
	}
	res := make([]int, n)
	idx := 0
	i := 0
	for  i < n {
		res[i] = arr[idx]
		i+=1
		if arr[idx] == 0 && i < n{
			res[i] = 0
			i+= 1
		}
		idx += 1
	}
	for i := 0; i < n ; i++{
		arr[i] = res[i]
	}
}

func main(){

	arr := []int{8,4,5,0,0,0,0,7}
	duplicateZeros(arr)
	fmt.Println(arr)
}