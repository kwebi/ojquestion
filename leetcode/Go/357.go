package main

import "fmt"

func countNumbersWithUniqueDigits(n int) int {
	var k = n
	if k < 2 {
		k = 2
	}
	dp := make([]int, k+1)
	dp[0], dp[1], dp[2] = 1, 10, 91
	for i := 3; i <= k; i++ {
		var t int = 1
		for j := 10; j >= 10-i+1; j-- {
			t *= j
		}
		var t1 = 1
		for j := 9; j >= 9-i+2; j-- {
			t1 *= j
		}
		t = t-t1
		dp[i] = t + dp[i-1]
	}
	return dp[n]
}

func main() {
	fmt.Println(countNumbersWithUniqueDigits(3))
}
