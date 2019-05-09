#include <algorithm>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;
const int maxn = 1010;

char a[maxn][maxn];
int ans[maxn][maxn];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int genx[1010][1010];
int geny[1010][1010];
int curx, cury; // 用来存储当前
int n, m;

int res;

void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return;
    if (ans[x][y] > -1)
        return;
    ++res;
    genx[x][y] = curx;
    geny[x][y] = cury;
    ans[x][y] = 0;
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (a[tx][ty] != a[x][y])
            dfs(tx, ty);
    }
}

int main()
{
    memset(ans, -1, sizeof(ans)); // 这里为什么要初始化成-1呢？因为 这样子方便后面判重（后面设为0来判重）
    memset(genx, 0, sizeof(genx));
    memset(geny, 0, sizeof(geny));

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        int y;

        cin >> x >> y;
        if (ans[genx[x][y]][geny[x][y]] > 0)
            cout << ans[genx[x][y]][geny[x][y]] << endl;
        else
        {
            curx = x;
            cury = y;
            res = 0;
            dfs(x, y);
            cout << res << endl;
            ans[x][y] = res;
            genx[x][y] = x;
            geny[x][y] = y;
        }
    }

    return 0;
}
