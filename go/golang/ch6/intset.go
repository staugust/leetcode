package main

import (
	"bytes"
	"fmt"
	"io"
)

type IntSet struct {
	words []uint64
}

func (p *IntSet) Has(x int) bool {
	word, bit := x/64, uint(x%64)
	return word < len(p.words) && p.words[word]&(1<<bit) != 0
}

func (p *IntSet) Add(x int) {
	word, bit := x/64, uint(x%64)
	for word >= len(p.words) {
		p.words = append(p.words, 0)
	}
	p.words[word] |= 1 << bit
}

func (p *IntSet) UnionWith(t *IntSet) {
	for i, tword := range t.words {
		if i < len(p.words) {
			p.words[i] |= tword
		} else {
			p.words = append(p.words, tword)
		}
	}
}

func (p *IntSet) String() string {
	var buf bytes.Buffer
	buf.WriteByte('{')
	for i, word := range (p.words) {
		if word == 0 {
			continue
		}
		for j := 0; j != 64; j++ {
			if word&(1<<uint(j)) != 0 {
				if buf.Len() > len("{") {
					buf.WriteByte(' ')
				}
				fmt.Fprintf(&buf, "%d", 64*i+j)
			}
			
		}
	}
	buf.WriteByte('}')
	return buf.String()
}

func (p *IntSet) Len() int {
	c := 0
	for _, word := range (p.words) {
		if word == 0 {
			continue
		}
		for j := 0; j != 64; j++ {
			if word&(1<<uint(j)) != 0 {
				c++
			}
		}
	}
	return c
}

func (p *IntSet) Remove(x int) {
	word, bit := x/64, uint(x%64)
	if word <= len(p.words) {
		p.words[word] ^= 1 << bit
	}
}

func (p *IntSet) Clear() {
	p.words = make([]uint64, 0)
}

func (p *IntSet) Copy() *IntSet {
	var st IntSet
	st.words = make([]uint64, len(p.words))
	copy(st.words, p.words)
	return &st
}

func (p *IntSet) AddAll(args ...int) {
	for _, v := range args {
		p.Add(v)
	}
}

func (p *IntSet) Intersection(s *IntSet) (r *IntSet) {
	r = new(IntSet)
	for i, tword := range s.words {
		if i >= len(p.words) {
			break
		}
		r.words = append(r.words, 0)
		r.words[i] = p.words[i] & tword
	}
	return
}

func (p *IntSet) MinusWith(t *IntSet) {
	for i, tword := range t.words {
		if i >= len(p.words) {
			break
		}
		p.words[i] &^= tword
	}
}

func (p *IntSet) SymmetricMinus(t *IntSet) (r *IntSet) {
	r = new(IntSet)
	var l = len(p.words)
	if l < len(t.words) {
		l = len(t.words)
	}
	r.words = make([]uint64, l)
	for i := 0; i != l; i++ {
		if i < len(p.words) {
			r.words[i] = r.words[i] ^ p.words[i]
		}
		if i < len(t.words) {
			r.words[i] = r.words[i] ^ t.words[i]
		}
	}
	return
}

func (p *IntSet) Elems() (s []int) {
	for i, word := range (p.words) {
		if word == 0 {
			continue
		}
		for j := 0; j != 64; j++ {
			if word&(1<<uint(j)) != 0 {
				s = append(s, 64*i+j)
			}
		}
	}
	return
}

type Text interface {
}

type Type struct {
	txt string
}

func main() {
	
	var t1 = Type{"Error"}
	var t2 = Type{"Error"}
	fmt.Println(t1 == t2)
	var r = 1
	switch r {
	case 1:
		r += 1
	case 2 :
		r += 1
	case 3:
		r += 1
	default:
		r += 3
	}
	fmt.Println(r)
	fmt.Println(&t1 == &t2)
	var i1 Text
	var i2 interface{}
	fmt.Println(i1 == i2)
	var buf *bytes.Buffer
	fmt.Println(buf == nil)
	fmt.Println(io.Writer(buf) == nil)
	fmt.Println(io.Writer(buf), buf)
	
	var x, y IntSet
	x.AddAll(1, 2, 3, 4, 300, 400)
	y.AddAll(1, 2, 100, 200)
	for _, v := range x.Elems() {
		fmt.Println(v)
	}
	fmt.Println("----------------------------------")
	
	fmt.Println(x.Len())
	x.Remove(400)
	fmt.Println(x.String())
	x.Clear()
	fmt.Println(x.String())
	x = *y.Copy()
	
	x.AddAll(4, 6, 8)
	x.Remove(100)
	fmt.Println(x.String())
	fmt.Println(x.Intersection(&y))
	fmt.Println(x.SymmetricMinus(&y))
	x.MinusWith(&y)
	fmt.Println(x.String())
}
