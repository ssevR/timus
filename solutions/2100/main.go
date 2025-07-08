package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	res := n + 2
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		if len(s) >= 4 && s[len(s)-4:] == "+one" {
			res++
		}
	}
	if res == 13 {
		res++
	}
	fmt.Println(res * 100)
}
