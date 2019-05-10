#include <vector>
#include <cstring>
#include <stdio.h>
#include <algorithm>

using namespace std;

int a[13];
int n, sum;
bool vis[13];
bool flag = false;
vector<int> res;

int C(int u, int d)
{
    if (u > d / 2)
        u = d - u;
    int a = 1, b = 1;
    for (int i = 0; i < u; ++i)
    {
        a *= (d - i);
        b *= (i + 1);
    }
    return a / b;
}

void dfs(int dep, int s)
{
    if (flag)
        return;
    if (dep > n || s > sum)
        return;
    if (dep == n)
    {
        if (s == sum)
        {
            flag = true;
            for (int i = 0; i < res.size(); ++i)
                printf("%d ", res[i]);
        }
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            vis[i] = true;
            int p = C(dep, n - 1);
            res.push_back(a[i]);
            dfs(dep + 1, s + a[i] * p);
            res.pop_back();
            vis[i] = false;
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &n, &sum);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    dfs(0, 0);
    return 0;
}
