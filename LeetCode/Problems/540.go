package main

func singleNonDuplicate(nums []int) int {
	xor := 0
	for i := 0; i < len(nums); i++ {
		xor ^= nums[i]
	}
	return xor
}
