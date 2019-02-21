package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var res = make([][]int,0)

func levelOrder(root *TreeNode) [][]int {
	res = make([][]int,0)
	if root == nil {
		return res
	}
	dfs(root, 0)
	return res
}

func dfs(r *TreeNode, dep int)  {
	if dep > len(res)-1 {
		res = append(res, make([]int,0))
	}
	res[dep]=append(res[dep], r.Val)
	if r.Left!=nil {
		dfs(r.Left,dep+1)
	}
	if r.Right!=nil {
		dfs(r.Right,dep+1)
	}
}

func main()  {
	r := TreeNode{
		Val:3,
		Left:&TreeNode{9,nil,nil},
		Right:&TreeNode{
			20,
			&TreeNode{15,nil,nil},
			&TreeNode{17,nil,nil},
		},
	}

	res := levelOrder(&r)
	fmt.Println(res)
}


