/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
	values := make(map[int]bool)
	for _, val := range to_delete {
		values[val] = true
	}
	if root == nil {
		return make([]*TreeNode, 0)
	}
	stk :=  make([]*TreeNode, 0)
	stk = append(stk, root)
	res := make([]*TreeNode, 0)
	if _, ok := values[root.Val]; !ok {
		res = append(res, root)
	}
	for len(stk) > 0{
		node := stk[0]
		stk = stk[1:]
		if node == nil {
			continue
		}
		stk = append(stk, node.Left, node.Right)
		_, shouldRemove := values[node.Val]
		if node.Left != nil {
			if _, ok:= values[node.Left.Val]; ok {
				node.Left = nil
			}else{
				if shouldRemove {
					res = append(res, node.Left)
				}
			}
		}
		if node.Right != nil {
			if _, ok := values[node.Right.Val]; ok {
				node.Right = nil
			}else{
				if shouldRemove {
					res = append(res, node.Right)
				}
			}
		}
	}
	return res
}

func main(){


}
