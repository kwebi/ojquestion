#include <stdio.h>

int sum(int a)
{
    int ans = 0;
    while (a > 0) {
        ans += a % 10;
        a /= 10;
    }
    return ans;
}

int main()
{
    int a;
    scanf("%d", &a);
    bool f = false;
    int i;
    for (i = a; !f;i++) {
        int s = sum(i);
        if (s % 4 == 0) {
            f = 1;
        }

    }
    printf("%d",--i);
    return 0;
}