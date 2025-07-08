package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	dx := []int{2, 2, -2, -2, 1, 1, -1, -1}
	dy := []int{-1, 1, -1, 1, 2, -2, 2, -2}
	for i := 0; i < n; i++ {
		var a string
		fmt.Scan(&a)
		x := int(a[0] - 'a')
		y := int(a[1] - '1')
		res := 0
		for i := 0; i < 8; i++ {
			tox := x + dx[i]
			toy := y + dy[i]
			if 0 <= tox && tox < 8 && 0 <= toy && toy < 8 {
				res++
			}
		}
		fmt.Println(res)
	}

}
