package main

func longestCommonPrefix(strs []string) string {
	ret := ""
	for i := 0; ; i++ {
		if equal(strs, i) {
			ret += string(strs[0][i])
		} else {
			break
		}
	}
	return ret
}

func equal(strs []string, i int) bool {
	for j := 0; j < len(strs); j++ {
		if i == len(strs[j]) {
			return false
		}
		if j != 0 && strs[j][i] != strs[j-1][i] {
			return false
		}
	}
	return true
}
