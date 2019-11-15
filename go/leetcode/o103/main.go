/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

func distributeCandies(candies int, num_people int) []int {
	k := 1
	c := 0
	for ; ; {
		c = (num_people * k) * (num_people*k + 1) / 2
		if c >= candies {
			break
		}
		k+=1
	}
	res := make([]int, 0)
	k = k - 1
	for i := 0; i < num_people; i++ {
		can := (2*(i+1) + num_people*(k-1)) * k / 2
		res = append(res, can)
		candies -= can
	}
	for i := 0; i < num_people; i++ {
		can := num_people*k + (i + 1)
		if candies >= can {
			res[i] += can
			candies -= can
		} else {
			res[i] += candies
			break
		}
	}
	return res
}

func main() {
	fmt.Println(distributeCandies(10,3))
}
