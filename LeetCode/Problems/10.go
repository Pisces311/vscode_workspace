package main

import "fmt"

func main() {
	s, p := "aaa", "a*"
	fmt.Println(isMatch(s, p))
}

func isMatch(s string, p string) bool {
	n, m := len(s), len(p)
	dp := make([][]bool, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]bool, m+1)
	}
	dp[0][0] = true
	s, p = "#"+s, "#"+p
	for j := 1; j <= m; j++ {
		if j > 1 && dp[0][j-2] && p[j] == '*' {
			dp[0][j] = true
		}
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if dp[i-1][j-1] {
				if s[i] == p[j] || p[j] == '.' {
					dp[i][j] = true
				} else if p[j] == '*' {
					if s[i] == s[i-1] || p[j-1] == '.' {
						dp[i][j] = true
					}
				}
			}
			if dp[i-1][j] && p[j] == '*' {
				if p[j-1] == '.' || (s[i] == s[i-1] && p[j-1] == s[i]) {
					dp[i][j] = true
				}
			}
			if dp[i][j-1] && p[j] == '*' {
				dp[i][j] = true
			}
			if j > 1 && dp[i][j-2] && p[j] == '*' {
				dp[i][j] = true
			}
		}
	}
	return dp[n][m]
}
