package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	if k >= n {
		fmt.Println(2)
	} else {
		fmt.Println((2*n + k - 1) / k)
	}
}
