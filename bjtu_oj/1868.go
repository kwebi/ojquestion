package main

import "fmt"

func main() {
	var n, q int
	var s string
	fmt.Scan(&n, &q)
	fmt.Scan(&s)
	root := make([]int, n+1)
	for i := 0; i <= n; i++ {
		root[i] = i
	}
	root[n] = n + 1
	for i := 0; i < q; i++ {
		var l, r int
		fmt.Scan(&l, &r)
		t := l - 1
		res := 0
		for t <= r-1 {
			if root[t] != t {
				t = root[t]
			} else {
				if s[t] == 'A' {
					root[t] = r
					res++
				}
				t++
			}
		}
		fmt.Println(res)
		root[r-1] = r
	}
}
