package main

import "fmt"

func lengthOfLIS(nums []int) int {
	l := len(nums)
	if l == 0 {
		return 0
	}
	var arr = []int{nums[0]}
	for i := 1; i < l; i++ {
		if nums[i] > arr[len(arr)-1] {
			arr = append(arr, nums[i])
		} else {
			index := BinarySearch(arr, nums[i])
			arr[index] = nums[i]
		}
	}

	return len(arr)
}

func BinarySearch(arr []int, n int) int {
	l := len(arr)
	beg := 0
	end := l - 1
	for beg < end {
		mid := (beg + end) / 2
		if n > arr[mid] {
			beg = mid + 1
		} else if n < arr[mid] {
			end = mid
		} else if n == arr[mid] {
			return mid
		}
	}
	return end
}

func main() {
	var arr = []int{1, 3, 6, 7, 9, 10, 13, 16, 18, 21, 24, 26}
	fmt.Println(BinarySearch(arr, 19))
	fmt.Println(lengthOfLIS([]int{10, 9, 2, 5, 3, 7, 101, 18}))
}
