#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int R, C;
int a[MAXN][MAXN];

int b[MAXN][MAXN];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ans = 1;

int dfs(int x, int y)
{
    if (b[x][y])
        return b[x][y];
    int t = 1;
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (x < 1 || x > R || y < 1 || y > C)
            continue;

        if (a[tx][ty] > a[x][y])
        {
            t = max(dfs(tx, ty) + 1, t);
        }
    }

    b[x][y] = t;
    return t;
}

int main()
{

    memset(b, 0, sizeof(b));

    scanf("%d%d", &R, &C);
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            ans = max(dfs(i, j), ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}
