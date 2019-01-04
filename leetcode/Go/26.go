package main

import "fmt"

func removeDuplicates(nums []int) int {
	length := len(nums)
	var i, j  int
	j = 1
	for i = 0; i < length-1; i++ {
		if nums[i] != nums[i+1] {
			nums[j]=nums[i+1]
			j++
		}
	}
	return j
}

func main() {
	arr := []int{1, 2,2}
	fmt.Println(removeDuplicates(arr))
}
