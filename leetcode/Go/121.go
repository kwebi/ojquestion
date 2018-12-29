package main

import (
	"fmt"
	"math"
)

func maxProfit(prices []int) int {
	l := len(prices)
	dp := make([]int, l)
	var global = 0
	var min = math.MaxInt32
	for i := 0; i < l; i++ {
		min = minInt(min, prices[i])
		dp[i] = prices[i] - min
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
	arr := []int{7,6,4,3,1}
	fmt.Println(maxProfit(arr))
}
