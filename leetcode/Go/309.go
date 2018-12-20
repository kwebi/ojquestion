package main

import (
	"math"
)

func maxProfit(prices []int) int {
	l := len(prices)
	s0 := make([]int, l)
	s1 := make([]int, l)
	s2 := make([]int, l)
	if l == 0 {
		return 0
	}
	s0[0] = 0
	s1[0] = -prices[0]
	s2[0] = math.MinInt32
	for i := 1; i < l; i++ {
		s0[i] = maxInt(s0[i-1], s2[i-1])
		s1[i] = maxInt(s0[i-1]-prices[i], s1[i-1])
		s2[i] = s1[i-1] + prices[i]
	}
	return maxInt(maxInt(s0[l-1], s1[l-1]), s2[l-1])
}
