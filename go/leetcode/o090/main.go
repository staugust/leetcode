/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "sort"

type Val struct {
	Value int
	Label int
}

type Slice []Val

func (s Slice) Len() int {
	return len(s)
}

func (s Slice) Less(i int, j int) bool {
	return s[i].Value > s[j].Value
}

func (s Slice) Swap(i int, j int) {
	s[i].Value, s[j].Value = s[j].Value, s[i].Value
	s[i].Label, s[j].Label = s[j].Label, s[i].Label
}

func largestValsFromLabels(values []int, labels []int, num_wanted int, use_limit int) int {
	if use_limit <= 0 {
		return 0
	}
	que := make(Slice, len(values))
	for idx := 0; idx < len(values); idx++ {
		que[idx] = Val{values[idx], labels[idx]}
	}
	sort.Sort(que)
	sum := 0
	mp := make(map[int]int)
	for idx:=0; num_wanted > 0 && idx < len(values) ; idx++{
		val, label := que[idx].Value, que[idx].Label
		if used, ok := mp[label]; ok && used >= use_limit {
			continue
		}
		mp[label] += 1
		num_wanted -=1
		sum += val
	}
  return sum
}

