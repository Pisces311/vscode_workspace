package main

import "fmt"

func main() {
	var t int
	fmt.Scan(&t)
	for cas := 0; cas < t; cas++ {
		var n int
		fmt.Scan(&n)
		a := make([]int, 2*n)
		for i := 0; i < 2*n; i++ {
			fmt.Scan(&a[i])
		}
		cnt := 0
		for i := 0; i < 2*n; i++ {
			if a[i]&1 == 1 {
				cnt++
			}
		}
		if cnt == n {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
