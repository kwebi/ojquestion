package main

import "fmt"

func findCircleNum(M [][]int) int {
	n := len(M)
	root := make([]int, n)
	for i := 0; i < n; i++ {
		root[i] = i
	}
	m := make(map[int]int)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if M[i][j] == 1 {
				union(root, i, j)
			}
		}
	}
	for i := 0; i < n; i++ {
		tmp := getRoot(root, i)
		if _, ok := m[tmp]; !ok {
			m[tmp] = 1
		}
	}
	return len(m)
}

func getRoot(root []int, i int) int {
	for i != root[i] {
		i = root[i]
	}
	return i
}

func union(root []int, i int, j int)  {
	if i != j {
		n := getRoot(root, i)
		rj := getRoot(root, j)
		if n != rj {
			root[n] = rj
		}
	}
}

func main() {
	arr := [][]int{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}
	fmt.Println(findCircleNum(arr))
}
