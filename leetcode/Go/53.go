package main

import "fmt"

func maxSubArray(nums []int) int {
	global := nums[0]
	local := maxInt(0, nums[0])
	for i := 1; i < len(nums); i++ {
		if nums[i]+local < 0 {
			local = 0
			global = maxInt(global, nums[i])
			continue
		}
		local += nums[i]
		global = maxInt(local, global)
	}
	return global
}

func maxInt(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main()  {
	arr := []int{-2,-1}
	fmt.Println(maxSubArray(arr))
}
