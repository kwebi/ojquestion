#include <cstring>
#include <stdio.h>

char a[505];
char b[505];
int res[505];
int cnt = 0;

void add(char a[], char b[], int l1, int l2)
{

    for (int i = l1 - 1, j = l2 - 1; i >= 0 || j >= 0; i--, j--) {
        if (i >= 0) {
            res[cnt] += a[i] - '0';
        }
        if (j >= 0) {
            res[cnt] += b[j] - '0';
        }
        cnt++;
    }
    for (int i = 0; i < cnt; i++) {
        if (res[i] >= 10) {
            res[i] -= 10;
            res[i + 1]++;
            if (i == cnt - 1) {
                cnt++;
            }
        }
    }
}

int main()
{
    scanf("%s", a);
    scanf("%s", b);
    int l1 = strlen(a);
    int l2 = strlen(b);
    add(a,b,l1,l2);
    for(int i=cnt-1;i>=0;i--) {
        printf("%d",res[i]);
    }
    printf("\n");
    return 0;
}
