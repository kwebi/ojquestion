#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 7;
const int M = 1e6 + 7;

vector<pii> v[N];
int ans[M];
int cnt = 0;

void dfs(int x, int y, int t)
{
    if (y < 0 || v[x][y].second < t || cnt >= M - 3)
        return;
    //printf("%d %d %d\n",v[x][y].first,y,t);
    ans[++cnt] = v[x][y].first;
    dfs(v[x][y].first, v[v[x][y].first].size() - 1, v[x][y].second);
    dfs(x, y - 1, t);
}

int main()
{
    int n;
    int l, r;
    scanf("%d%d%d", &n, &l, &r);
    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(pii(y, i));
    }
    dfs(0,v[0].size()-1,0);
    for (int i = l; i < r; i++) {
        printf("%d ", ans[i%(cnt+1)]);
    }
    return 0;
}
