package main

import "math/rand"

type RandomizedSet struct {
	Data map[int]int
	Array []int
}


/** Initialize your data structure here. */
func Constructor() RandomizedSet {
	return RandomizedSet{
		Data: make(map[int]int),
		Array: make([]int, 0),
	}
}


/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.Data[val]; !ok {
		this.Data[val] = len(this.Array)
		this.Array = append(this.Array, val)
		return true
	}
	return false
}


func (this *RandomizedSet) Remove(val int) bool {
	if _, ok := this.Data[val]; !ok {
		return false
	}
	index := this.Data[val]
	tmp := this.Array[index]
	this.Array[index] = this.Array[len(this.Array)-1]
	this.Array[len(this.Array)-1] = tmp
	this.Data[this.Array[index]] = index
	delete(this.Data, this.Array[len(this.Array)-1])
	this.Array = this.Array[0:len(this.Array)-1]
	return true
}


/** Get a random element from the set. */
func (this *RandomizedSet) GetRandom() int {
	r := rand.Intn(len(this.Array))
	return this.Array[int(r)]
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
