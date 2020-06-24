#include <bits/stdc++.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n % 4 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}