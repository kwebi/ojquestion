
#include <stdio.h>

const int maxn = 1e5 + 5;
typedef long long LL;

struct Node {
    int l, r, flag;
    LL w;
    Node() {}
    Node(int _l, int _r, LL _w, int _f)
    {
        l = _l, r = _r, w = _w, flag = _f;
    }
    int mid()
    {
        return (l + r) / 2;
    }
};

Node tr[maxn << 2];

void build(int k, int l, int r)
{
    tr[k] = Node(l, r, 0, 0);
    if (tr[k].l == tr[k].r) {
        scanf("%lld", &tr[k].w);
        return;
    }
    build(k << 1, l, (l + r) / 2);
    build(k << 1 | 1, (l + r) / 2 + 1, r);
    tr[k].w = tr[k << 1].w + tr[k << 1 | 1].w;
}

void down(int k)
{ //延迟标记下传
    tr[k << 1].flag += tr[k].flag;
    tr[k << 1 | 1].flag += tr[k].flag;
    tr[k << 1].w += tr[k].flag * (tr[k << 1].r - tr[k << 1].l + 1);
    tr[k << 1 | 1].w += tr[k].flag * (tr[k << 1 | 1].r - tr[k << 1 | 1].l + 1);
    tr[k].flag = 0;
}

void update(int k, int x, int y, int z)
{ //区间更新
    if (tr[k].l >= x && tr[k].r <= y) {
        tr[k].w += z * (tr[k].r - tr[k].l + 1);
        tr[k].flag += z;
        return;
    }
    if (tr[k].flag)
        down(k);
    if (x <= tr[k].mid())
        update(k << 1, x, y, z);
    if (y > tr[k].mid())
        update(k << 1 | 1, x, y, z);
    tr[k].w = tr[k << 1].w + tr[k << 1 | 1].w;
}

LL query(int k, int x, int y)
{
    LL res = 0;
    if (tr[k].l >= x && tr[k].r <= y) {
        return tr[k].w;
    }
    if (tr[k].flag)
        down(k);
    if (x <= tr[k].mid())
        res += query(k << 1, x, y);
    if (y > tr[k].mid())
        res += query(k << 1 | 1, x, y);
    return res;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int a;
        int x, y, k;
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &x, &y, &k);
            update(1, x, y, k);
        } else {
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, x, y));
        }
    }
    return 0;
}
