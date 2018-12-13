package main

func maximalSquare(matrix [][]byte) int {
	var global = 0
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}
	var m = len(matrix)
	var n = len(matrix[0])
	var dp [][]int
	for i := 0; i < m; i++ {
		dp = append(dp, make([]int, n))
	}
	global = 0
	for i := 0; i < m; i++ {
		dp[i][0] = int(matrix[i][0] - '0')
		global = maxInt(global, dp[i][0])
	}
	for i := 0; i < n; i++ {
		dp[0][i] = int(matrix[0][i] - '0')
		global = maxInt(global, dp[0][i])
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][j] != '0' {
				dp[i][j] = minThreeInt(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
				global = maxInt(global, dp[i][j])
			}
		}
	}

	return global * global
}

func minThreeInt(a int, b int, c int) int {
	if a > b {
		a = b
	}
	if a > c {
		a = c
	}
	return a
}
