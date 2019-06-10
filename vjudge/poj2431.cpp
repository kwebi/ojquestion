#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5;

struct Stop
{
    int a;
    int f;
} s[maxn];

bool cmp(Stop a, Stop b)
{
    return a.a < b.a;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &s[i].a, &s[i].f);
    int L, P;
    sort(s + 1, s + n + 1, cmp);
    s[0].a = 0;
    s[0].f = 0;
    scanf("%d%d", &L, &P);
    priority_queue<int> pque;
    int tank = P, pos = 0, ans = 0;
    for (int i = n; i >= 0; --i)
    {
        int d = (L - s[i].a) - pos;
        while (tank < d)
        {
            if (pque.empty())
                return puts("-1"), 0;
            tank += pque.top();
            pque.pop();
            ++ans;
        }
        pque.push(s[i].f);
        pos = L - s[i].a;
        tank -= d;
    }
    printf("%d", ans);
    return 0;
}
