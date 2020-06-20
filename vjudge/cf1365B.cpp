#include <stdio.h>

int a[1010];
int b[1010];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int tr = 0, fl = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            tr |= b[i];
            fl &= b[i];
        }
        if (tr == 1 && fl == 0) {
            printf("Yes\n");
        } else {
            int fg = 1;
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i - 1]) {
                    fg = 0;
                    break;
                }
            }
            if (fg) {
                printf("Yes\n");
            } else
                printf("No\n");
        }
    }
    return 0;
}