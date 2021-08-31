package main

import "sort"

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	nums1 = append(nums1, nums2...)
	sort.Ints(nums1)
	middle := len(nums1) / 2
	if len(nums1)&1 == 1 {
		return float64(nums1[middle])
	} else {
		return (float64(nums1[middle]) + float64(nums1[middle-1])) / 2
	}
}
