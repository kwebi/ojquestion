#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

vector<int> G[maxn];
bool vis[maxn];
int n;
long long n1, n2;

void dfs(int v, int step)
{
    for (int i = 0; i < G[v].size(); ++i)
    {
        if (!vis[G[v][i]])
        {
            vis[G[v][i]] = 1;
            if (step & 1)
                ++n1;
            else
                ++n2;
            dfs(G[v][i], step + 1);
        }
    }
}

int main()
{

    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    n1 = 1;
    vis[1] = 1;
    dfs(1, 0);
    printf("%lld", n1 * n2 - (n - 1));

    return 0;
}
