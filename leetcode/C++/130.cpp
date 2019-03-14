#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<bool>> visited;
    int n;
    int m;
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        n = board.size();
        m = board[0].size();
        visited.resize(board.size());
        for (auto &e : visited)
        {
            e = vector<bool>(board[0].size());
        }
        for (int i = 0; i < n; ++i)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1);
        }
        for (int j = 0; j < m; ++j)
        {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[n - 1][j] == 'O')
                dfs(board, n - 1, j);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        visited[i][j] = true;
        if (i + 1 < n && board[i + 1][j] == 'O' && !visited[i + 1][j])
        {
            dfs(board, i + 1, j);
        }
        if (j + 1 < m && board[i][j + 1] == 'O' && !visited[i][j + 1])
        {
            dfs(board, i, j + 1);
        }
        if (i - 1 >= 0 && board[i - 1][j] == 'O' && !visited[i - 1][j])
        {
            dfs(board, i - 1, j);
        }
        if (j - 1 >= 0 && board[i][j - 1] == 'O' && !visited[i][j - 1])
        {
            dfs(board, i, j - 1);
        }
    }
};