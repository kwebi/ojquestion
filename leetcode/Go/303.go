package main

type NumArray struct {
	dp []int
}


func Constructor(nums []int) NumArray {
	for i := 1; i < len(nums); i++ {
		nums[i] = nums[i-1]+nums[i]
	}
	return NumArray{nums}
}


func (this *NumArray) SumRange(i int, j int) int {
	if i == 0 {
		return this.dp[j]
	}
	return this.dp[j]-this.dp[i-1]
}
