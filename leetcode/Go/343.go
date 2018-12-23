package main

func integerBreak(n int) int {
	dp := [59]int{}
	dp[2] = 1
	for i := 2; i <= n; i++ {
		for j := 1; j < i; j++ {
			dp[i] = maxInt(dp[i-j]*j, maxInt(dp[i], (i-j)*j))
		}
	}
	return dp[n]
}
