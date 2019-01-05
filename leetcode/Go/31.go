package main

import "sort"

func nextPermutation(nums []int)  {
	l := len(nums)
	j := -1
	var i int
	var t int
	for i=0;i<l-1;i++{
		if nums[i]<nums[i+1] {
			j = i
		}
		if j!=-1&& nums[j] < nums[i+1] {
			t = i+1
		}
	}
	if j != -1 {
		nums[j],nums[t] = nums[t],nums[j]
		sort.Sort(sort.IntSlice(nums[j+1:]))
	} else {
		sort.Sort(sort.IntSlice(nums))
	}
}

func main()  {
	arr := []int{3,2,1}
	nextPermutation(arr)
}