package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	l := len(s)
	if l == 0 {
		return 0
	} else if l == 1 {
		return 1
	}
	global := -1
	dp := make([]int, l)
	dp[0] = 1
	res := 1
	for i := 1; i < l; i++ {
		dp[i] = -1
		for j := i - 1; j >= 0; j-- {
			if s[i] == s[j] {
				dp[i] = j
				break
			}
		}
		global = maxInt(global, dp[i])
		res = maxInt(i-global, res)
	}
	return res
}

func lengthOfLongestSubstringO(s string) int {
	stack := make(map[byte]int)
	var start, maxl int

	for i := 0; i < len(s); i++ {
		if v, ok := stack[s[i]]; ok && v >= start {
			start = v + 1
		}
		maxl = maxInt(maxl, i-start+1)
		stack[s[i]] = i
	}
	return maxl
}

func maxInt(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Println(lengthOfLongestSubstring("aubcccdefg"))
}
