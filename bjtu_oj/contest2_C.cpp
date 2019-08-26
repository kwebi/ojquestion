#include <stdio.h>
#include <map>
using namespace std;

const int maxn = 2e5 + 5;

int a[maxn];
map<int, int> vis;
int odd = 0;
int o = 1, e = 2;
int n, m;
bool flag = true;

void change_e(int i)
{
    while (e <= m && vis[e]) //找下一个可以用的偶数
        e += 2;
    if (e > m)
        flag = false;
    else
        vis[e]++, vis[a[i]]--, a[i] = e;
}

void change_o(int i)
{
    while (o <= m && vis[o])
        o += 2;
    if (o > m)
        flag = false;
    else
        vis[o]++, vis[a[i]]--, a[i] = o;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] & 1)
            ++odd;
        ++vis[a[i]];
    }
    o = 1;
    e = 2;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (vis[a[i]] == 1)
            continue;
        ++ans;
        if (odd > n / 2)
        {
            if (a[i] & 1)
                --odd;
            change_e(i);
        }
        else if (odd == n / 2)
        {
            if (a[i] & 1)
                change_o(i);
            else
                change_e(i);
        }
        else
        {
            if (a[i] % 2 == 0)
                ++odd;
            change_o(i);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (odd > n / 2 && a[i] & 1)
        {
            change_e(i);
            --odd;
            ++ans;
        }
        if (odd < n / 2 && a[i] % 2 == 0)
        {
            change_o(i);
            ++odd;
            ++ans;
        }
        if (odd == n / 2)
            break;
    }
    if (!flag || odd != n / 2)
        return puts("-1"), 0;
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    return 0;
}
