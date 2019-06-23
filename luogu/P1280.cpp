#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 1e4 + 5;
struct Th {
    int p, t;
    bool operator<(const Th& b)
    {
        return p < b.p;
    }
};

bool cmp(const Th& a, const Th& b)
{
    return a.p > b.p;
}
Th a[maxn];

int f[maxn]; //第i分钟到第n分钟的最大休闲时间
vector<int> ks[maxn];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &a[i].p, &a[i].t);
        ks[a[i].p].push_back(a[i].t);
    }
    for (int i = n; i > 0; i--) {
        if (ks[i].size() > 0) {
            for (int j = 0; j < ks[i].size(); j++) {
                f[i] = max(f[i], f[i + ks[i][j]]);
            }
        } else {
            f[i] = f[i + 1] + 1;
        }
    }
    printf("%d\n", f[1]);
    return 0;
}
