#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}; //方向数组
const int dy[] = {1, 0, -1, 1, -1, 0, 1, -1};

char str[] = "yizhong";
char s[105][105];
char ans[105][105];
int used[105][105] = {0};

int n;

void dfs(int x, int y)
{
    for (int i = 0; i < 8; ++i)
    {
        bool flag = true;
        for (int j = 1; j <= 6; ++j)
        {
            int nx = x + j * dx[i];
            int ny = y + j * dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n)
            {
                flag = false;
                break;
            }
            if (str[j] != s[nx][ny])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            continue;
        for (int j = 0; j <= 6; ++j)
        {
            int nx = x + j * dx[i];
            int ny = y + j * dy[i];
            ans[nx][ny] = s[nx][ny];
        }
    }
}

int main()
{
    vector<pair<int,int>> m;
    memset(ans, '*', sizeof(ans));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == 'y')
                m.push_back(make_pair(i,j));
        }
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        dfs(it->first, it->second);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
