package main

import (
	"fmt"
	"strconv"
	"strings"
)

/*
https://leetcode.com/problems/invalid-transactions/
*/

type Transac struct {
	Time   int
	Amount int
	City   string
	Origin string
	Valid  bool
}

func Parse(str string) (string, *Transac) {
	infos := strings.Split(str, ",")
	name := infos[0]
	time, _ := strconv.Atoi(infos[1])
	amount, _ := strconv.Atoi(infos[2])
	city := infos[3]
	return name, &Transac{
		time,
		amount,
		city,
		str,
		true,
	}
}

type Trans struct {
	Trans []*Transac
}

func (t *Trans) InsertOne(trac *Transac) {
	if trac.Amount >= 1000 {
		trac.Valid = false
	}
	var idx int
	var found bool
	for i := 0; i < len(t.Trans); i++ {
		interval := t.Trans[i].Time - trac.Time
		if interval >= -60 && interval <= 60 {
			if t.Trans[i].City != trac.City {
				trac.Valid = false
				t.Trans[i].Valid = false
			}

		}
		if interval >= 0 && !found {
			found = true
			idx = i
		}
	}
	if found {
		last := make([]*Transac, len(t.Trans[idx:]))
		copy(last, t.Trans[idx:])
		t.Trans = append(t.Trans[:idx], trac)
		t.Trans = append(t.Trans, last...)

	} else {
		t.Trans = append(t.Trans, trac)
	}
}

func invalidTransactions(transactions []string) []string {
	var mt = make(map[string]*Trans)
	invalidTrac := make([]string, 0)
	for _, trac := range transactions {
		name, t := Parse(trac)
		var ts *Trans
		var ok = false
		if ts, ok = mt[name]; !ok {
			ts = &Trans{
				Trans: make([]*Transac, 0),
			}
			mt[name] = ts
		}
		ts.InsertOne(t)
	}
	for _, trac := range mt {
		for _, t := range trac.Trans {
			if t.Valid == false {
				invalidTrac = append(invalidTrac, t.Origin)
			}
		}
	}
	return invalidTrac
}

func main() {
	trans := []string{"bob,689,1910,barcelona", "alex,696,122,bangkok", "bob,832,1726,barcelona", "bob,820,596,bangkok", "chalicefy,217,669,barcelona", "bob,175,221,amsterdam"}
	fmt.Println(invalidTransactions(trans))

}
