#include <stdio.h>

const int maxn = 5e5 + 5;

int tree[maxn], n;

int lowbit(int x)
{
    return x & -x;
}

int query(int x) 
{
    int ans = 0;
    for (int i = x; i != 0; i -= lowbit(i)) {
        ans += tree[i];
    }
    return ans;
}

void update(int x, int y, int n) //单点更新
{
    for (int i = x; i <= n; i += lowbit(i)) { //x为更新的位置,y为更新后的数,n为数组最大值
        tree[i] += y;
    }
}

void rangeAdd(int l, int r, int x) //区间修改
{
    update(l, x, n);
    update(r + 1, -x, n);
}

int m;

int main()
{
    scanf("%d%d", &n, &m);
    int pre = 0;

    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        update(i, num - pre, n);//维护差分数组
        pre = num;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &b, &c, &d);
            rangeAdd(b, c, d);
        } else {
            scanf("%d", &b);
            printf("%d\n", query(b));
        }
    }
    return 0;
}
