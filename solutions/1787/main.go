package main

import "fmt"

func main() {
	var k, n int
	fmt.Scan(&k, &n)
	res := 0

	for i := 0; i < n; i++ {
		var a int
		fmt.Scan(&a)
		res += a
		res -= k
		if res < 0 {
			res = 0
		}
	}
	fmt.Println(res)
}
