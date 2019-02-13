#include <vector>
using namespace std;

class Solution
{
  public:
    int v1[10][10]={0};
    int v2[10][10]={0};
    int v3[10][10]={0};
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int num=board[i][j]-'1',k=j/3+(i/3)*3;
                    if(v1[i][num]==1||v2[j][num]==1||v3[k][num]==1)
                        return false;
                    v1[i][num]=v2[j][num]=v3[k][num]=1;
                }
            }
        }
        return true;
    }
};