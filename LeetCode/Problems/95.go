package main

func main() {

}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(start, end int) []*TreeNode {
	ret := make([]*TreeNode, 0)
	if start > end {
		return nil
	}
	if start == end {
		return []*TreeNode{{start, nil, nil}}
	}
	for i := start; i <= end; i++ {
		left, right := dfs(start, i-1), dfs(i+1, end)
		for _, l := range left {
			for _, r := range right {
				ret = append(ret, &TreeNode{i, l, r})
			}
		}
	}
	return ret
}

func generateTrees(n int) []*TreeNode {
	return dfs(1, n)
}
