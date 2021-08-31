package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	m := make(map[byte]int)
	ans := 0
	for l, r := 0, 0; r < len(s); r++ {
		m[s[r]]++
		for m[s[r]] > 1 {
			m[s[l]]--
			l += 1
		}
		ans = max(ans, r-l+1)
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Println(lengthOfLongestSubstring("abcabcbb"))
}
