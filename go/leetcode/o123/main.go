/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

import "fmt"

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func copySlice(s []*TreeNode) []*TreeNode{
	res := make([]*TreeNode, len(s))
	for idx, val := range s {
		res[idx] = val
	}
	return res
}

func rootFirstTraverse(root *TreeNode, path []*TreeNode, Paths *[][]*TreeNode) {
	path = append(path, root)
	if root.Left == nil && root.Right == nil {
		if len(*Paths) == 0 {
			*Paths = append(*Paths, copySlice(path))
		} else {
			if len( (*Paths)[0]) == len(path) {
				*Paths = append(*Paths, copySlice(path))
			}else if len((*Paths)[0]) < len(path) {
				*Paths = make([][]*TreeNode, 1)
				(*Paths)[0] = copySlice(path)
			}
		}
		return
	}
	if root.Left != nil {
		rootFirstTraverse(root.Left, path, Paths)
	}
	if root.Right != nil {
		rootFirstTraverse(root.Right, path, Paths)
	}
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	path := make([]*TreeNode, 0)
	Paths := make([][]*TreeNode, 0)
	rootFirstTraverse(root, path, &Paths)
	if len(Paths) == 0 {
		return nil
	}
	for idx := 0; idx < len(Paths[0]); idx++{
		node := Paths[0][idx]
		for j := 1; j < len(Paths); j++ {
			if Paths[j][idx] != node {
				return Paths[j][idx - 1]
			}
		}
	}
	return Paths[0][len(Paths[0]) - 1]
}

func main() {
	root := &TreeNode{1, &TreeNode{Val:3}, &TreeNode{Val:2}}
	root.Left.Right = &TreeNode{Val: 8}
	root.Right.Left = &TreeNode{Val:4, Right:&TreeNode{Val:5, Right:&TreeNode{Val:7, Left:&TreeNode{Val: 9, Left:&TreeNode{Val:10}, Right:&TreeNode{Val:12}}}}}
	root.Right.Right = &TreeNode{Val: 6, Left:&TreeNode{Val: 11}}
	fmt.Println(lcaDeepestLeaves(root))
}
