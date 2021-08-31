package main

import (
	"fmt"
	"sort"
)

func minPatches(nums []int, n int) int {
	len := len(nums)
	sort.Ints(nums)
	cur, ret := 1, 0
	for i := 0; i < len; i++ {
		if cur < nums[i] {
			ret += 1
			cur *= 2
			i--
		} else {
			cur += nums[i]
		}
		if cur > n {
			break
		}
	}
	for cur <= n {
		ret += 1
		cur *= 2
	}
	return ret
}

func main() {
	fmt.Println(minPatches([]int{1, 2, 31, 33}, 2147483647))
}
