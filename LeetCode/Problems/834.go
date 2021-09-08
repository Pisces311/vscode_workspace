package main

import "fmt"

func main() {
	fmt.Println(sumOfDistancesInTree(6, [][]int{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}}))
}

var (
	dis  []int
	son  []int
	tree [][]int
	ret  []int
	N    int
)

func sumOfDistancesInTree(n int, edges [][]int) []int {
	N = n
	tree = make([][]int, n)
	for i := 0; i < n; i++ {
		tree[i] = make([]int, 0)
	}
	for _, edge := range edges {
		tree[edge[0]] = append(tree[edge[0]], edge[1])
		tree[edge[1]] = append(tree[edge[1]], edge[0])
	}
	dis = make([]int, n)
	son = make([]int, n)
	dfs1(0, -1, 0)
	ret = make([]int, n)
	for i := 0; i < len(dis); i++ {
		ret[0] += dis[i]
	}
	dfs2(0, -1)
	return ret
}

func dfs1(u, fa, d int) {
	dis[u] = d
	son[u] = 1
	for _, v := range tree[u] {
		if v != fa {
			dfs1(v, u, d+1)
			son[u] += son[v]
		}
	}
}

func dfs2(u, fa int) {
	for _, v := range tree[u] {
		if v != fa {
			ret[v] = ret[u] - son[v] + N - son[v]
			dfs2(v, u)
		}
	}

}
