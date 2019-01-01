package main

import (
	"fmt"
	"math"
	. "./compare"
)

func getMoneyAmount(n int) int {
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, n+1)
	}
	for i := n - 1; i > 0; i-- {
		for j := i + 1; j <= n; j++ {
			dp[i][j] = math.MaxInt32
			for k := i; k < j; k++ {
				dp[i][j] = MinInt(dp[i][j], k+MaxInt(dp[i][k-1], dp[k+1][j]))
			}
		}
	}
	return dp[1][n]
}

func main() {
	fmt.Println(getMoneyAmount(10))
}
