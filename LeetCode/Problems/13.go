package main

func romanToInt(s string) int {
	Map := make(map[string]int)
	sign := []string{"M", "D", "C", "L", "X", "V", "I"}
	nums := []int{1000, 500, 100, 50, 10, 5, 1}
	for i := 0; i < 7; i++ {
		Map[sign[i]] = nums[i]
	}
	ret := 0
	for i := 0; i < len(s); i++ {
		if i < len(s)-1 && Map[s[i:i+1]] < Map[s[i+1:i+2]] {
			ret -= Map[s[i:i+1]]
		} else {
			ret += Map[s[i:i+1]]
		}
	}
	return ret
}
