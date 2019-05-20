#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    int n = k;
    if (k == 0)
        puts("a");

    for (int c = 'a'; c <= 'z' && n; ++c)
    {
        int i;
        for (i = 1; n - (i - 1) * i / 2 >= 0; ++i)
            ;
        --i;
        for (int j = 0; j < i; ++j)
        {
            printf("%c", c);
        }
        n -= (i - 1) * i / 2;
    }
    return 0;
}
