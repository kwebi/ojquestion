package main

func lengthOfLIS(nums []int) int {
	l := len(nums)
	if l == 0 {
		return 0
	}
	dp := make([]int, l)
	dp[0] = 1
	var global = 1
	for i := 0; i < l-1; i++ {
		var j int
		var local = nums[i+1]
		dp[i+1] = 1
		for j = i; j >= 0; j-- {
			if local > nums[j] {
				dp[i+1] = maxInt(dp[j]+1, dp[i+1])
			}
		}
		global = maxInt(global, dp[i+1])
	}
	return global
}
