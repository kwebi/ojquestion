#include <stdio.h>

const int maxn = 1e7 + 5;

bool a[maxn];

void prime(int n)
{
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!a[i]) {
            for (int j = i * 2; j <= n; j += i) {
                a[j] = 1;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    prime(n);
    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        if (!a[num])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
