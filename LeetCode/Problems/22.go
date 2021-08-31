package main

import "fmt"

var ret []string

func solve(cur string, l, r int) {
	if l == 0 && r == 0 {
		ret = append(ret, cur)
		return
	}
	if l > 0 {
		solve(cur+"(", l-1, r+1)
	}
	if r > 0 {
		solve(cur+")", l, r-1)
	}
}

func generateParenthesis(n int) []string {
	ret = make([]string, 0)
	solve("", n, 0)
	return ret
}

func main() {
	fmt.Println(generateParenthesis(3))
}
