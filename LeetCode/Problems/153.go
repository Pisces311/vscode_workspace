package main

import "fmt"

func main() {
	fmt.Println(findMin([]int{2, 1}))
}

func findMin(nums []int) int {
	l, r := 0, len(nums)-1
	ans := nums[0]
	for l <= r {
		mid := (l + r) / 2
		if nums[mid] >= nums[0] {
			l = mid + 1
		} else {
			r = mid - 1
			ans = nums[mid]
		}
	}
	return ans
}
