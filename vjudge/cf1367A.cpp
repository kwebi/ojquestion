#include <stdio.h>
#include <string.h>

char s[110];
char ans[110];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {

        scanf("%s", s);
        int len = strlen(s);
        int m = 0;
        printf("%c", s[0]);
        for (int i = 1; i < len; i += 2) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}