package main

import "fmt"

func findDuplicate(nums []int) int {
	abs := func(k int) int {
		if k < 0{
			return -k
		}
		return k
	}
	for i:= 0; i < len(nums); i++{
		if nums[abs(nums[i])] > 0 {
			nums[abs(nums[i])] = -nums[abs(nums[i])]
		}else{
			return abs(nums[i])
		}
	}
	return -1
}

type Test struct {
	Desc string
}

func (t *Test) GetDesc() string {
	return t.Desc
}

func main(){
	var str = fmt.Sprintf("yo, what's up %s ? ", "man")
	t := &Test{
		str,
	}
	d := t.GetDesc()
	t.Desc = "yo, nidaye zai ci"
	fmt.Println(d, t.GetDesc())


}