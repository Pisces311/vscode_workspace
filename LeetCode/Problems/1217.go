package main

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func minCostToMoveChips(position []int) int {
	odd, even := 0, 0
	for i := 0; i < len(position); i++ {
		if position[i]%2 == 0 {
			even++
		} else {
			odd++
		}
	}
	return min(odd, even)
}
