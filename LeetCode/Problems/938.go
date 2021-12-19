package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var sum int

func dfs(root *TreeNode, low int, high int) {
	if root == nil {
		return
	}
	if low <= root.Val && root.Val <= high {
		sum += root.Val
	}
	dfs(root.Left, low, high)
	dfs(root.Right, low, high)
}

func rangeSumBST(root *TreeNode, low int, high int) int {
	sum = 0
	dfs(root, low, high)
	return sum
}
