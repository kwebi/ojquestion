#include <stdio.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, q;
    char s[1000000];
    scanf("%d %d", &n, &q);
    scanf("%s", s);
    vector<int> root(n + 1);
    for (int i = 0; i < n; i++)
    {
        root[i] = i;
    }
    root[n] = n + 1;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        int t = l - 1;
        int res = 0;
        while (t <= r - 1)
        {
            if (root[t] != t)
            {
                t = root[t];
            }
            else
            {
                if (s[t] == 'A')
                {
                    root[t] = r;
                    res++;
                }
                t++;
            }
        }
        printf("%d\n", res);
        root[r - 1] = r;
    }

    return 0;
}
