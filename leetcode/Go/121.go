package main

import (
	"fmt"
)

func maxProfit(prices []int) int {
	l := len(prices)
	dp := make([]int, l)
	var global = 0
	for i := l - 1; i > 0; i-- {
		for j := i - 1; j >= 0; j-- {
			dp[i] = maxInt(dp[i], prices[i]-prices[j])
		}
		global = maxInt(global, dp[i])
	}
	return global
}

func maxInt(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func minInt(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	arr := []int{7,1,5,3,6,4}
	fmt.Println(maxProfit(arr))
}
