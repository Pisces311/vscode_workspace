package main

func intToRoman(num int) string {
	sign := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	nums := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	ret := ""
	for i := 0; i < 13; i++ {
		for num >= nums[i] {
			num -= nums[i]
			ret += sign[i]
		}
	}
	return ret
}
