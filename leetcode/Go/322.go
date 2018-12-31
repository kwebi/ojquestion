package main

import (
	. "./compare"
	"fmt"
	"math"
)

func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
	dp[0] = 0
	for i := 1; i <= amount; i++ {
		dp[i] = math.MaxInt32
		for _, v := range coins {
			if i-v < 0 {
				continue
			}
			dp[i] = MinInt(dp[i], dp[i-v]+1)
		}
	}
	if dp[amount] == math.MaxInt32 {
		return -1
	}
	return dp[amount]
}

func main()  {
	fmt.Println(coinChange([]int{10}, 11))
}
