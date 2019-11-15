/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

func sampleStats(count []int) []float64 {
	var tt = int64(0)
	var total = int64(0)
	var min, max, mean, median,  mode float64
	min = -1
	max = -1
	mx := 0
	for i:=0; i < len(count); i++{
		if count[i] == 0{
			continue
		}
		if min == -1 {
			min = float64(i)
		}
		if count[i] > mx{
			mx = count[i]
			mode = float64(i)
		}
		tt += int64(i) * int64(count[i])
		total += int64(count[i])
	}
	mean = float64(tt) / float64(total)
	first := int((total+1) / 2)
  second := first
  if total % 2 == 0 {
  	second = first + 1
	}
  var f, s , no int = -1, -1, 0
  no = int(total)
	for i:= len(count) - 1; i >= 0; i-- {
		if count[i] == 0{
			continue
		}
		if max == -1 {
			max = float64(i)
		}

		no -= count[i]
		if no  < second && s == -1 {
			s = i
		}
		if no  < first && f == -1 {
			f = i
			break
		}
	}
	median = (float64(f) + float64(s)) / 2.000
  return []float64{min, max, mean, median, mode}
}

func main(){

	fmt.Println(sampleStats([]int{0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}))
}
