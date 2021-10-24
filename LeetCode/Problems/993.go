package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var (
	parent map[int]int
	depth  map[int]int
)

func dfs(root *TreeNode, fa, d int) {
	if root == nil {
		return
	}
	parent[root.Val] = fa
	depth[root.Val] = d
	dfs(root.Left, root.Val, d+1)
	dfs(root.Right, root.Val, d+1)
}

func isCousins(root *TreeNode, x int, y int) bool {
	parent = make(map[int]int)
	depth = make(map[int]int)
	dfs(root, -1, 1)
	return depth[x] == depth[y] && parent[x] != parent[y]
}
