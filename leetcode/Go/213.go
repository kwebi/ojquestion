package main

func rob2(nums []int) int {
	a, b := 0, 0
	for i := 0; i < len(nums)-1; i++ {
		m, n := a, b
		a = n + nums[i]
		b = maxInt(m, n)
	}
	length := len(nums)
	if length <= 2 {
		if length == 1 {
			return nums[0]
		} else if length == 0 {
			return 0
		} else if length == 2 {
			return maxInt(nums[0], nums[1])
		}
	}
	r1 := maxInt(a, b)
	a, b = 0, 0
	for i := 1; i < len(nums); i++ {
		m, n := a, b
		a = n + nums[i]
		b = maxInt(m, n)
	}
	r2 := maxInt(a, b)
	return maxInt(r1, r2)
}
