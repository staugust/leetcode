/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rootFirst(root *TreeNode, limit int, sum *int, mp map[*TreeNode]bool) {
	*sum += root.Val
	if root.Left == nil && root.Right == nil {
		if *sum < limit {
			mp[root] = true
		}
	} else {
		shouldDelete := true
		if root.Left != nil {
			rootFirst(root.Left, limit, sum, mp)
			if _, ok := mp[root.Left]; !ok {
				shouldDelete = false
			}
		}
		if root.Right != nil {
			rootFirst(root.Right, limit, sum, mp)
			if _, ok := mp[root.Right]; !ok {
				shouldDelete = false
			}
		}
		if shouldDelete {
			mp[root] = shouldDelete
		}
	}
	*sum -= root.Val
}

func delRootFirst(root *TreeNode, shouldDelete map[*TreeNode]bool) {
	if root.Left != nil {
		if _, ok := shouldDelete[root.Left]; ok {
			root.Left = nil
		} else {
			delRootFirst(root.Left, shouldDelete)
		}
	}
	if root.Right != nil {
		if _, ok := shouldDelete[root.Right]; ok {
			root.Right = nil
		} else {
			delRootFirst(root.Right, shouldDelete)
		}
	}
}

func sufficientSubset(root *TreeNode, limit int) *TreeNode {
	if root == nil {
		return nil
	}
	sum := 0
	shouldDelete := make(map[*TreeNode]bool)
	rootFirst(root, limit, &sum, shouldDelete)
	if _, ok := shouldDelete[root]; ok {
		return nil
	}
	delRootFirst(root, shouldDelete)
	return root
}


func sufficientSubset2(root *TreeNode, limit int) *TreeNode {
	return solve(root, limit, 0)
}

func solve(root *TreeNode, limit int, sum int) *TreeNode {
	if root == nil {
		return nil
	}

	val := sum + root.Val

	// is leaf
	if root.Left == nil && root.Right == nil {
		if val < limit {
			return nil
		}
		return root
	}

	left  := solve(root.Left, limit, val)
	right := solve(root.Right, limit, val)

	root.Left = left
	root.Right = right

	if left == nil && right == nil {
		return nil
	}

	return root
}

func NewNode(val, left, right int) *TreeNode {
	node := &TreeNode{
		Val: val,
	}
	if left != 0 {
		node.Left = &TreeNode{Val: left}
	}
	if right != 0 {
		node.Right = &TreeNode{Val: right}
	}
	return node
}

func main() {
	n31 := NewNode(4, 8, 9)
	n32 := NewNode(-99, -99, -99)
	n33 := NewNode(-99, 12, 13)
	n34 := NewNode(7, -99, 14)
	n21 := &TreeNode{
		Val:   2,
		Left:  n31,
		Right: n32,
	}
	n22 := &TreeNode{
		Val:   3,
		Left:  n33,
		Right: n34,
	}
	root := &TreeNode{
		Val:   1,
		Left:  n21,
		Right: n22,
	}

	sufficientSubset(root, 1)

}
