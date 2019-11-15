/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

func maxDepthAfterSplit(seq string) []int {
	res := make([]int, len(seq))
	lenA, lenB := 0, 0
	halfA, halfB := 0, 0
	for idx, c := range seq {
		if c == '('{
			if lenA < lenB || (lenA == lenB && halfA <= halfB){
				res[idx] = 0
				halfA += 1
				if lenA < halfA {
					lenA = halfA
				}
			}else {
				res[idx] = 1
				halfB += 1
				if lenB < halfB {
					lenB = halfB
				}
			}
		}else{
			if halfA >= halfB{
				res[idx] = 0
				halfA -= 1
			}else{
				res[idx] = 1
				halfB -= 1
			}
		}
	}
	return res
}

func maxDepthAfterSplit2(seq string) []int {
	ans := make([]int, len(seq))
	level := 0
	for i, s := range seq {
		if s == '(' {
			level++
			ans[i] = level & 1
		} else {
			ans[i] = level & 1
			level--
		}
	}
	return ans
}


func main(){

	str := "(((()))((())))"
	res := maxDepthAfterSplit(str)
	s1, s2 := "",""
	for idx, val := range res{
		if val == 0 {
			s1 += string(str[idx])
		}else{
			s2 += string(str[idx])
		}
	}
	fmt.Println(str)
	fmt.Println(s1)
	fmt.Println(s2)



}