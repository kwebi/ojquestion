#include <bits/stdc++.h>
char s[1000];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int cnt0 = 0;
        int cnt1 = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (s[i] == '0')
                cnt0++;
            if (s[i] == '1')
                cnt1++;
        }
        int mi = cnt0 < cnt1 ? cnt0 : cnt1;
        if (mi % 2 == 0) {
            printf("NET\n");
        } else {
            printf("DA\n");
        }
    }
    return 0;
}