package main

import (
	"fmt"
	"sort"
)

/*
  https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
*/

func removeSubfolders(folder []string) []string {
	sort.Strings(folder)
	res := make(map[string]bool)
	for _, f := range folder {
		if len(f) == 1 {
			return []string{"/"}
		}
		func() {
			var j int
			for j = 1; j < len(f); j++ {
				if f[j] == '/' {
					if _, ok := res[f[:j]]; ok {
						return
					}
				}
			}
			if j == len(f) {
				res[f] = true
			}
		}()
	}
	arr := make([]string, len(res))
	var idx = 0
	for key := range res {
		arr[idx] = key
		idx += 1
	}
	return arr
}

func main() {
	folder := []string{"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"}
	fmt.Println(removeSubfolders(folder))
}
