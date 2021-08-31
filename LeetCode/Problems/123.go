package main

import "fmt"

func maxProfit(prices []int) int {
	n := len(prices)
	right, left := make([]int, n), make([]int, n)
	ma, mi := 0, 100000
	for i := n - 1; i >= 0; i-- {
		ma = max(ma, prices[i])
		right[i] = ma - prices[i]
		if i != n-1 {
			right[i] = max(right[i], right[i+1])
		}
	}
	for i := 0; i < n; i++ {
		mi = min(mi, prices[i])
		left[i] = prices[i] - mi
		if i != 0 {
			left[i] = max(left[i], left[i-1])
		}
	}
	ans := max(right[0], left[n-1])
	for i := 1; i < n-1; i++ {
		ans = max(ans, left[i-1]+right[i])
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func main() {
	fmt.Println(maxProfit([]int{3, 3, 5, 0, 0, 3, 1, 4}))
}
