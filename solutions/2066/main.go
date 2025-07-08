package main

import "fmt"

func min(vals ...int) int {
	m := vals[0]
	for _, v := range vals[1:] {
		if v < m {
			m = v
		}
	}
	return m
}

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	res := min(a*b*c, a*b+c, a*b-c, a+b*c, a+b+c, a+b-c, a-b*c, a-b+c, a-b-c)
	fmt.Println(res)
}
