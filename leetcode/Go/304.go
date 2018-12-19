package main

type NumMatrix struct {
	matrix [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	for i := 0; i < len(matrix); i++ {
		for j := 1; j < len(matrix[0]); j++ {
			matrix[i][j] = matrix[i][j] + matrix[i][j-1]
		}
	}
	for i := 1; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			matrix[i][j] = matrix[i-1][j] + matrix[i][j]
		}
	}
	return NumMatrix{matrix: matrix}
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	if row1 == 0 {
		if col1 == 0 {
			return this.matrix[row2][col2]
		} else {
			return this.matrix[row2][col2] - this.matrix[row2][col1-1]
		}
	} else {
		if col1 == 0 {
			return this.matrix[row2][col2] - this.matrix[row1-1][col2]
		} else {
			return this.matrix[row2][col2] - this.matrix[row1-1][col2] - this.matrix[row2][col1-1] + this.matrix[row1-1][col1-1]
		}
	}
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
