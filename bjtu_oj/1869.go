package main

import "fmt"

func main() {
	var x, y, k int64
	_, _ = fmt.Scanf("%d %d %d", &x, &y, &k)
	var res = x * k
	var i int64
	for i = 0; i <= k/3+1; i++ {
		if k-3*i > 0 {
			res = MinInt(res, (k-3*i)*x+i*y)
		} else {
			res = MinInt(res, i*y)
		}
	}
	fmt.Println(res)
}

func MinInt(a int64, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
