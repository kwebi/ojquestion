package main

import "fmt"

func countNumbersWithUniqueDigits(n int) int {
	if n == 0 {
		return 1
	}
	dp := make([]int, n+2)
	dp[0] = 1
	dp[1] = 9
	res := dp[0] + dp[1]
	for i := 2; i <= n; i++ {
		dp[i] = (11-i)*dp[i-1]
		res += dp[i]
	}
	return res
}

func main() {
	fmt.Println(countNumbersWithUniqueDigits(3))
}
