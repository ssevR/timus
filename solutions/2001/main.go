package main

import "fmt"

func main() {
	var a, b [3]int
	for i := 0; i < 3; i++ {
		fmt.Scan(&a[i], &b[i])
	}
	fmt.Println(a[0]-a[2], b[0]-b[1])
}
