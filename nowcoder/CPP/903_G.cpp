#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 0 || n == 1)
    {
        printf("qiandaoshibai");
        return 0;
    }

    --n;
    if (n % 2 == 1)
        printf("qiandaochenggong");
    else
        printf("qiandaoshibai");
    return 0;
}
