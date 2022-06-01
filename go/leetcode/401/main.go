package main

import "fmt"

var hours = [][]string{[]string{"0"},
	[]string{"1", "2", "4", "8"},
	[]string{"12", "6", "10", "3", "5", "9"},
	[]string{"7", "11"}}

var minutes = [][]string{
	[]string{"0"},
	[]string{"1", "2", "4", "8", "16", "32"},
	[]string{"48", "24", "40", "12", "20", "36", "6", "10", "18", "34", "3", "5", "9", "17", "33"},
	[]string{"56", "52", "28", "44", "50", "26", "42", "14", "22", "38", "49", "25", "41", "13", "21", "37", "7", "11", "19", "35"},
	[]string{"60", "58", "54", "30", "46", "57", "53", "29", "45", "51", "27", "43", "15", "23", "39"},
	[]string{"59", "55", "31", "47"},
}

func readBinaryWatch(num int) []string {
	res := make([]string, 0)
	for i := 0; i <= num; i++ {
		if i < len(hours) && (num-i) < len(minutes) {
			hs := hours[i]
			ms := minutes[num-i]
			for h := range hs {
				for m := range ms {
					res = append(res, fmt.Sprintf("%s:%s", h, m))
				}
			}
		}
	}
	return res
}

func main() {

}
