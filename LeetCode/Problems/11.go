package main

func maxArea(height []int) int {
	n := len(height)
	ans := 0
	for l, r := 0, n-1; l < r; {
		ans = max(ans, min(height[l], height[r])*(r-l))
		if height[l] < height[r] {
			l++
		} else {
			r--
		}
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
