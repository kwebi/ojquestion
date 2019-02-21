package main

func searchInsert(nums []int, target int) int {
	beg := 0
	end := len(nums)
	for beg < end {
		mid := (beg + end) / 2
		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			end = mid
		} else if nums[mid] < target {
			beg = mid + 1
		}
	}
	return end
}
