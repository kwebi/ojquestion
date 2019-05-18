#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

int k[205];
bool vis[205];
int n, a, b;
int ans[205];

void bfs(int i)
{
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    ans[i] = 0;
    while (!q.empty())
    {
        int j = q.front();
        q.pop();
        if (j == b)
        {
            return;
        }
        int x = j - k[j];
        int y = j + k[j];
        if (!vis[x] && x > 0 && x <= n)
        {
            q.push(x);
            ans[x] = ans[j] + 1;
            vis[x] = 1;
        }
        if (!vis[y] && y > 0 && y <= n)
        {
            q.push(y);
            ans[y] = ans[j] + 1;
            vis[y] = 1;
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &k[i]);
    bfs(a);
    printf("%d\n", ans[b]);
    return 0;
}
