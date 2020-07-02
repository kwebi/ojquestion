#include <bits/stdc++.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n == 1 || n == 2)
            printf("1\n");
        else {
            printf("%d\n", (n + 1) / 2);
        }
    }

    return 0;
}