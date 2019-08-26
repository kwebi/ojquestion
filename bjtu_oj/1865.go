package main

import "fmt"

func main()  {
	var n int64
	_, _ = fmt.Scanf("%d", &n)
	var res int64 = 0
	if n%2 == 0 {
		res = n/2 - 1
	} else {
		res = n/2
	}
	fmt.Println(res)
}
