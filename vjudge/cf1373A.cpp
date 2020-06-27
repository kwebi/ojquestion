#include <bits/stdc++.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a >= c) {
            printf("-1 ");
        } else {
            printf("1 ");
        }
        if (c / b >= a) {
            printf("-1\n");
        } else {
            printf("%d\n", b);
        }
    }
    return 0;
}