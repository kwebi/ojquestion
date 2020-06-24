#include <bits/stdc++.h>
char s[100010];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        int l = n;
        int r = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                r = i;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                l = i;
            }
        }
        if (l != n && r != -1) {
            for (int i = 0; i < n; i++) {
                if (i >= l && i < r) {
                    continue;
                }
                printf("%c", s[i]);
            }
            printf("\n");
        } else {
            printf("%s\n", s);
        }
    }
    return 0;
}