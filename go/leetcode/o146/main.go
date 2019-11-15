/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

type SnapshotArray struct {
	Len int
	Dat map[int]int
	SnapId int
}


func Constructor(length int) SnapshotArray {
	sa := SnapshotArray{
		Len : length,
		Dat : make(map[int]int),
		SnapId: 0,
	}
	return sa
}


func (this *SnapshotArray) Set(index int, val int)  {
	this.Dat[index + this.Len * this.SnapId] = val
}


func (this *SnapshotArray) Snap() int {
	defer func() {
		this.SnapId+=1
	}()
	return this.SnapId
}


func (this *SnapshotArray) Get(index int, snap_id int) int {
	for idx := snap_id; idx >= 0; idx-- {
		if val, ok := this.Dat[index + this.Len * idx]; ok {
			return val
		}

	}
	return 0
}


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * obj := Constructor(length);
 * obj.Set(index,val);
 * param_2 := obj.Snap();
 * param_3 := obj.Get(index,snap_id);
 */