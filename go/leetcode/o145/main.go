/*
 * @author: Jinghua.Yao
 * @email : staugusto91@gmail.com
 */

package main


//Definition for a binary tree node.
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func sumNodes(root *TreeNode, n *int) {
	if root == nil {
		return
	}
	*n += 1
	sumNodes(root.Left, n)
	sumNodes(root.Right, n)
}

func findNode(root *TreeNode, x int) *TreeNode{
	if root == nil {
		return nil
	}
	if root.Val == x {
		return root
	}
	left := findNode(root.Left, x)
	if left != nil {
		return left
	}
	right := findNode(root.Right, x)

	if right != nil {
		return right
	}
	return nil
}

func btreeGameWinningMove(root *TreeNode, n int, x int) bool {
	node := findNode(root, x)
	var leftNodes, rightNodes = 0, 0
	sumNodes(node.Left, &leftNodes)
	var win = n  / 2
	if leftNodes > win {
		return true
	}
	sumNodes(node.Right, &rightNodes)
	if rightNodes > win {
		return true
	}
	if n - leftNodes - rightNodes - 1 > win {
		return true
	}
	return false
}