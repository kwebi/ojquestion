#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int arrN[200005];
int arrM[200005];
//高次方求模
int PowMod(int n, int p, int M)
{
    int result = 1;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            result = (result * n) % M;
        }
        p /= 2;
        n = (n * n) % M;
    }
    return result;
}

int main()
{

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        int N, M, D;
        scanf("%d %d %d", &N, &M, &D);
        for (int j = 0; j < N; ++j)
        {
            scanf("%d", &arrN[j]);
            arrN[j] = PowMod(arrN[j], arrN[j], D);
        }
        for (int j = 0; j < M; ++j)
        {
            scanf("%d", &arrM[j]);
        }
        sort(arrN, arrN + N);
        sort(arrM, arrM + M);
        int p1 = 0, p2 = 0;
        int res = 0;
        while (p1 < N && p2 < M)
        {
            if (arrN[p1] <= arrM[p2])
            {
                ++res;
                ++p1;
                ++p2;
            }
            else
            {
                ++p1;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}