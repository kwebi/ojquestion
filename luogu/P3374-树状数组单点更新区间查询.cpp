#include <stdio.h>

const int maxn = 5e5 + 5;

int tree[maxn], n;

int lowbit(int x)
{
    return x & -x;
}

int getSum(int x)
{
    int ans = 0;
    for (int i = x; i != 0; i -= lowbit(i)) {
        ans += tree[i];
    }
    return ans;
}

void add(int x, int y, int n)
{
    for (int i = x; i <= n; i += lowbit(i)) { //x为更新的位置,y为更新后的数,n为数组最大值
        tree[i] += y;
    }
}

int m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        add(i, num, n);
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1) {
            add(b, c, n);
        } else {
            printf("%d\n", getSum(c) - getSum(b - 1));
        }
    }
    return 0;
}
