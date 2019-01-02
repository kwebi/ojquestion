package main

import (
	"fmt"
	"math"
)

func main()  {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	var arr []int
	for i := k; i <= n; i++ {
		if DigitSum(i) == k {
			arr = append(arr, i)
		}
	}
	var res = 0
	for _, v := range arr {
		if IsPrime(v) {
			res++
		}
	}
	fmt.Println(res)
}

func DigitSum(n int) int {
	var res = 0
	t := n
	for t >= 1{
		res += t%10
		t /= 10
	}
	return res
}

func IsPrime(n int) bool {
	for i := 2; float64(i) <= math.Sqrt(float64(n)); i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

