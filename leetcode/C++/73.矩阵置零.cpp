/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (51.44%)
 * Total Accepted:    8.7K
 * Total Submissions: 16.8K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 * 
 * 示例 1:
 * 
 * 输入: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * 输出: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * 输出: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 进阶:
 * 
 * 
 * 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个常数空间的解决方案吗？
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        int x = -1, y = -1;
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 0)
                x = 0;
        }
        for (int j = 0; j < n; ++j)
        {
            if (matrix[0][j] == 0)
                y = 0;
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 0; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; ++i)
        {
            if (matrix[0][i] == 0)
            {
                for (int j = 0; j < m; ++j)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        if (x == 0)
        {
            for (int i = 0; i < m; ++i)
            {
                matrix[i][0] = 0;
            }
        }
        if (y == 0)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[0][j] = 0;
            }
        }
    }
};
