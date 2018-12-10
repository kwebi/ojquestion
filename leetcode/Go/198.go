package main

func rob(nums []int) int {
	a, b := 0, 0
	for i := 0; i < len(nums); i++ {
		m, n := a, b
		a = n + nums[i]
		b = maxInt(m, n)
	}
	return maxInt(a, b)

}

func maxInt(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
