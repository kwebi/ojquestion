#include <stdio.h>

typedef long long LL;

const int maxn = 1e5 + 5;

LL tr[maxn];
LL extr[maxn];
int n;

void update(LL p, LL x)
{
    for (LL i = p; i <= n; i += i & -i) {
        tr[i] += x;
        extr[i] += x * p;
    }
}

void rangeAdd(LL l, LL r, LL x)
{
    update(l, x);
    update(r + 1, -x);
}

LL query(LL p)
{
    LL res = 0;
    for (LL i = p; i; i -= i & -i) {
        res += (p + 1) * tr[i] - extr[i];
    }
    return res;
}

LL rangeQ(LL l, LL r)
{
    return query(r) - query(l - 1);
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    LL pre = 0;
    for (int i = 1; i <= n; i++) {
        LL num;
        scanf("%lld", &num);
        update(i, num - pre);
        pre = num;
    }
    for (int i = 1; i <= m; i++) {
        int a;
        int x, y, k;
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &x, &y, &k);
            rangeAdd(x, y, k);
        } else {
            scanf("%d%d", &x, &y);
            printf("%lld\n", rangeQ(x, y));
        }
    }
    return 0;
}
