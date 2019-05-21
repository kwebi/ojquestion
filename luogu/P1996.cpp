#include <stdio.h>
#include <string.h>

int tree[200];

int get_head(int p)
{
    while (tree[p] != p)
    {
        p = tree[p];
    }
    return p;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        tree[i] = i;
    tree[n + 1] = 1;
    int pos = 1;
    int i = 1;
    int c = n;
    while (c > 0)
    {
        if (i == m)
        {
            printf("%d ", pos);
            tree[pos] = get_head(pos + 1);
            i = 0;
            --c;
        }
        ++i;
        pos = get_head(pos + 1);
    }
    return 0;
}
