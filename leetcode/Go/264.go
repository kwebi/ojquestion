package main

func nthUglyNumber(n int) int {
	var num [1695]int
	num[0] = 1
	var x, y, z = 0, 0, 0
	for i := 1; i < n; i++ {
		//始终确保 a, b, c 都大于 num[i-1]
		var a = num[x] * 2
		var b = num[y] * 3
		var c = num[z] * 5
		var min = minInt(a, minInt(b, c))
		if a == min {
			x++
		}
		if b == min {
			y++
		}
		if c == min {
			z++
		}
		num[i] = min
	}
	return num[n-1]
}
