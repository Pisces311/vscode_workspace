package main

import "fmt"

func main() {
	fmt.Println(arrayNesting([]int{5, 4, 0, 3, 1, 6, 2}))
}

var vis []bool

func arrayNesting(nums []int) int {
	vis = make([]bool, len(nums))
	ret := 0
	for i := 0; i < len(nums); i++ {
		if !vis[i] {
			ret = max(ret, dfs(nums, i, 1))
		}
	}
	return ret
}

func dfs(nums []int, u, cnt int) int {
	vis[u] = true
	v := nums[u]
	if vis[v] {
		return cnt
	}
	return dfs(nums, v, cnt+1)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
