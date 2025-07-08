package main

import "fmt"

func main() {
	var f int
	fmt.Scan(&f)
	f = 12 - f
	if f <= 5 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
