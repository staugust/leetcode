/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "sort"

type IntSlice []int

func (s IntSlice) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s IntSlice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Len() int {
	return len(s)
}


func relativeSortArray(arr1 []int, arr2 []int) []int {
	occur := make(map[int]int)
	for _, val := range arr2 {
		occur[val] = 0
	}
	tmp := make(IntSlice , 0)
	for _, val := range arr1 {
		if _, ok := occur[val]; ok {
			occur[val]+= 1
		}else{
			tmp = append(tmp, val)
		}
	}
	sort.Sort(tmp)
	res := make([]int, 0)
	for _, val := range arr2 {
		for i:=0; i < occur[val]; i++{
			res = append(res, val)
		}
	}
	return append(res, tmp...)
}

func main(){


}