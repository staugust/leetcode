/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 * https://leetcode.com/problems/car-pooling/
 */

package o094

func carPooling(trips [][]int, capacity int) bool {
	getUp := make(map[int]int,0)
	getOff := make(map[int]int , 0)
	maxDistance := int(0)
	for idx := 0; idx < len(trips); idx++{
		if _, ok := getUp[trips[idx][1]]; !ok{
			getUp[trips[idx][1]] = 0
		}
		getUp[trips[idx][1]] += trips[idx][0]
		if _, ok := getOff[trips[idx][2]]; !ok {
			getOff[trips[idx][2]] = 0
		}
		getOff[trips[idx][2]] += trips[idx][0]
		if maxDistance < trips[idx][2] {
			maxDistance = trips[idx][2]
		}
	}
	cur := int(0)
	for i:= 0; i <= maxDistance; i++{
		if cnt, ok := getOff[i]; ok{
			cur -= cnt
		}
		if cur < 0 {
			return false
		}
		if cnt, ok := getUp[i]; ok {
			cur += cnt
		}
		if cur > capacity {
			return false
		}

	}
  return true
}

func main() {

}