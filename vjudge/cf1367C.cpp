#include <stdio.h>
#include <string.h>

int a[200100];
int pos[200100];
char st[200100];
int cnt = 0;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        int k;
        cnt = 0;
        scanf("%d%d", &n, &k);
        scanf("%s", st);
        for (int i = 0; i < n; i++) {
            a[i] = st[i] - '0';
            if (a[i] == 1) {
                pos[cnt++] = i;
            }
        }
        int pre = 0;
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            int left = pos[i] - k;
            if (left > pre) {
                int len = left - pre;
                ans += (1 + (len - 1) / (k + 1));
            }
            pre = pos[i] + k + 1;
        }
        if (pre < n) {
            //printf("pre:%d\n", pre);
            int len = n - pre;
            ans += (1 + (len - 1) / (k + 1));
        }
        if (cnt == 0) {
            ans = (1 + (n - 1) / (k + 1));
        }
        printf("%d\n", ans);
    }
    return 0;
}