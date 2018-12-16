package main

import "math"

var arr []int

func numSquares(n int) int {
	arr = make([]int, n+1)
	for i := 0; i < n+1; i++ {
		arr[i] = math.MaxInt32
	}
	for i := 1; float64(i) <= math.Sqrt(float64(n)); i++ {
		arr[i*i] = 1
	}

	for i := 1; i <= n; i++ {
		for j := 1; i+j*j <= n; j++ {
			arr[i+j*j] = minInt(arr[i]+1, arr[i+j*j])
		}
	}
	return arr[n]
}
