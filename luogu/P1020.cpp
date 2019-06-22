#include <algorithm>
#include <map>
#include <stdio.h>

using namespace std;

const int maxn = 1e5 + 5;
const int INF = 1e9 + 7;
int a[maxn];
int dp[maxn];
int par[maxn];
bool vis[maxn] = { 0 };
int n = 0;

void init()
{
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int find(int x)
{
    vis[x] = 1;
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

int bsh(int l, int r, int val, int a[])
{
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < val) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main()
{
    while (~scanf("%d", &a[n])) {
        n++;
    }
    for (int i = 0; i < n; i++)
        dp[i] = -2;
    for (int i = 0; i < n; i++) {
        int it = bsh(0, n, a[i], dp);
        dp[it] = a[i];
    }
    int ans = bsh(0, n, -1, dp);
    printf("%d\n", ans);

    for (int i = 0; i < n; i++)
        dp[i] = INF;
    for (int i = 0; i < n; i++) {
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    printf("%d\n", lower_bound(dp, dp + n, INF) - dp);

    return 0;
}
