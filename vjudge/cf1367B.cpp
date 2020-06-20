#include <stdio.h>
#include <string.h>

int a[10010];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] % 2 == i % 2)
                continue;
            if (a[i] % 2 == 0)
                cnt0++;
            if (a[i] % 2 == 1)
                cnt1++;
        }
        if (cnt0 != cnt1) {
            printf("-1\n");
        } else {
            printf("%d\n", cnt0);
        }
    }
    return 0;
}