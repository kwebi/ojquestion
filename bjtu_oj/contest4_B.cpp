#include <stdio.h>

int judge(int a, int b, int c)
{
    int s1 = a + b;
    int s2 = b + c;
    int s3 = a + c;
    if (s1 > c && s2 > a && s3 > b)
        return 1;
    if (s1 == c || s2 == a || s3 == b)
        return 0;
    return -1;
}

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int t1 = judge(a, b, c);
    int t2 = judge(b, c, d);
    int t3 = judge(a, c, d);
    int t4 = judge(a, b, d);
    if (t1 == 1 || t2 == 1 || t3 == 1 || t4 == 1)
        return puts("TRIANGLE"), 0;
    if (t1 == 0 || t2 == 0 || t3 == 0 || t4 == 0)
        return puts("SEGMENT"), 0;
    puts("IMPOSSIBLE");
    return 0;
}
