package main

import "fmt"

func removeElement(nums []int, val int) int {
	l := len(nums)
	j := 0
	for i := 0; i < l; i++{
		if nums[i] != val {
			nums[j] = nums[i]
			j++
		}
	}
	return j
}

func main()  {
	arr := []int{3,1}
	fmt.Println(removeElement(arr,3))
}