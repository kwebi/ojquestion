package main

func maxProduct(nums []int) int {
	global := nums[0]
	local_min := nums[0]
	local_max := nums[0]
	for i := 1; i < len(nums); i++ {
		A := nums[i]
		local_max_copy := local_max
		local_max = maxInt(maxInt(A, A*local_max), local_min*A)
		local_min = minInt(minInt(A, A*local_max_copy), local_min*A)
		global = maxInt(global, local_max)
	}
	return global
}

func minInt(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
