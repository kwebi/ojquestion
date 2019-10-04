#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Node {
    ll l, v;
    int i;
    bool operator==(const Node& b) const
    {
        return l == b.l;
    }
    bool operator<(const Node& b) const
    {
        if (l == b.l)
            return i > b.i;
        return l < b.l;
    }
};

Node a[100100];
ll Tr[100100];
ll INF = 2e9;
int lowbit(int x) { return x & -x; }

void update(int x, ll y, int n)
{
    for (int i = x; i <= n; i += lowbit(i)) {
        Tr[i] = max(Tr[i], y);
    }
}

ll query(int x)
{
    ll ret = -INF;
    for (int i = x; i; i -= lowbit(i)) {
        ret = max(ret, Tr[i]);
    }
    return ret;
}


int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        a[i].l = l;
        a[i].i = i;
        a[i].v = r - l + 1;
    }
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        //printf("%d %d\n",a[i].l,a[i].i);
        ll mx = query(a[i].i);
        update(a[i].i, mx + a[i].v, n);
        mx = query(a[i].i);
        ans = max(ans, mx);
    }
    printf("%lld\n", ans);
    return 0;
}
