package main

import "fmt"

func main() {
	var a, b string
	fmt.Scan(&a, &b)
	if (a[3]-'0')%2 == 0 || (b[3]-'0')%2 == 1 {
		fmt.Println("yes")
	} else {
		fmt.Println("no")
	}
}
