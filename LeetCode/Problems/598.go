package main

func maxCount(m int, n int, ops [][]int) int {
	num := len(ops)
	for i := 0; i < num; i++ {
		m = min(m, ops[i][0])
		n = min(n, ops[i][1])
	}
	return m * n
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
