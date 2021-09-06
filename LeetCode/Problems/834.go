package main

func main() {

}

var dis []int

func sumOfDistancesInTree(n int, edges [][]int) []int {
	tree := make([][]int, n)
	for i := 0; i < n; i++ {
		tree[i] = make([]int, 0)
	}
	for _, edge := range edges {
		tree[edge[0]] = append(tree[edge[0]], edge[1])
		tree[edge[1]] = append(tree[edge[1]], edge[0])
	}
	dis = make([]int, n)
	dfs1(0, -1, 0, tree)
	ret := make([]int, n)
	for i := 0; i < len(dis); i++ {
		ret[0] += dis[i]
	}

	return dis
}

func dfs1(u, fa, d int, tree [][]int) {
	dis[u] = d
	for _, v := range tree[u] {
		if v != fa {
			dfs1(v, u, d+1, tree)
		}
	}
}
