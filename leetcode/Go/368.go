package main

import (
	"fmt"
	"sort"
)

func largestDivisibleSubset(nums []int) []int {
	res := []int{}
	l := len(nums)
	count := make([]int, l)
	pre := make([]int, l)
	sort.Ints(nums)
	max, index := 0, -1
	for i := 0; i < l; i++ {
		count[i] = 1
		pre[i] = -1
		for j := i-1; j >= 0; j-- {
			if nums[i]%nums[j] == 0 && 1+count[j] > count[i] {
				count[i] = count[j] + 1
				pre[i] = j
			}
		}
		if count[i] > max {
			max = count[i]
			index = i
		}
	}
	for index != -1 {
		res = append(res, nums[index])
		index = pre[index]
	}
	return res
}

func main() {
	fmt.Println(largestDivisibleSubset([]int{1, 2, 3, 6 }))
}
