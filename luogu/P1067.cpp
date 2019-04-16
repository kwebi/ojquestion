#include <stdio.h>

const int N = 2e5;
int a[N];

void print2(int n)
{
    if (n == 1)
        printf("x");
    else
        printf("x^%d", n);
}

void print1(int a, int n)
{
    if (a > 0)
    {
        printf("+");
        if (a == 1)
            print2(n);
        else
        {
            printf("%d", a);
            print2(n);
        }
    }
    else
    {
        printf("-");
        if (a == -1)
            print2(n);
        else
        {
            printf("%d", -a);
            print2(n);
        }
    }
}
void print3(int a, int n)
{
    if (a > 0)
    {
        if (a == 1)
            print2(n);
        else
        {
            printf("%d", a);
            print2(n);
        }
    }
    else
    {
        printf("-");
        if (a == -1)
            print2(n);
        else
        {
            printf("%d", -a);
            print2(n);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (i == n)
        {
            if (a[i] > 0)
                printf("+%d", a[i]);
            else if (a[i] < 0)
                printf("-%d", -a[i]);
        }
        else if (i == 0)
        {
            print3(a[i], n - i);
        }
        else
        {
            if (a[i] != 0)
                print1(a[i], n - i);
        }
    }

    return 0;
}
