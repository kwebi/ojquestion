#include <vector>
using namespace std;

class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n);
        for (auto &e : dp)
        {
            e.resize(m);
        }
        int global = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = matrix[i][0] - '0';
            global = maxInt(global, dp[i][0]);
        }
        for (int i = 0; i < m; ++i)
        {
            dp[0][i] = matrix[0][i] - '0';
            global = maxInt(global, dp[0][i]);
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {

                if (matrix[i][j] != '0')
                {
                    dp[i][j] = minInt(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                    global = maxInt(global, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return global * global;
    }
    int minInt(int a, int b, int c)
    {
        a = a > b ? b : a;
        return a > c ? c : a;
    }
    int maxInt(int a, int b)
    {
        return a > b ? a : b;
    }
};

int main()
{
    vector<vector<char>> m{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    vector<vector<char>> m1{{'1'}};
    Solution s;
    int res = s.maximalSquare(m1);
    return 0;
}