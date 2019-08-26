package main

import "fmt"

func main() {
	var n, x, y int64
	fmt.Scan(&n, &x, &y)
	for i := 1; int64(i) <= n; i++ {

		var l int64 = 0
		var r int64 = (1 << 60)
		var ai int64
		fmt.Scan(&ai)
		for l < r {
			var mid = (l + r) / 2
			if mid/x+mid/y >= ai {
				r = mid
			} else {
				l = mid + 1
			}
		}
		if r%x == 0 && (r%y == 0) {
			fmt.Printf("Both\n")
		} else if r%x == 0 {
			fmt.Printf("Vova\n")
		} else {
			fmt.Printf("Vanya\n")
		}
	}
}
