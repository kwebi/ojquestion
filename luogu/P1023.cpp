#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 2e5;

int b[N];

int a[N];

double profit[N];

int main()
{

    int pre;
    int cost;
    int costpri;
    scanf("%d", &pre);
    scanf("%d%d", &cost, &costpri);
    a[0] = cost;
    b[0] = costpri;
    int n = 0;
    int prei = 0;
    while (true)
    {
        int ai, bi;
        scanf("%d%d", &ai, &bi);
        if (ai == -1 && bi == -1)
            break;
        a[ai - cost] = ai;
        b[ai - cost] = bi;
        if (ai - cost - prei > 1)
        {
            int c = (bi - b[prei]) / double(ai - cost - prei);
            for (int j = prei + 1; j < ai - cost; ++j)
            {
                a[j] = cost + j;
                b[j] = b[prei] + c * (j - prei);
            }
        }
        n = ai - cost;
        prei = n;
    }
    int reduce;
    scanf("%d", &reduce);
    int minb = b[n] - reduce;
    while (minb > 0)
    {
        ++n;
        b[n] = minb;
        a[n] = cost + n;
        minb -= reduce;
    }
    if (a[n] < pre)
    {
        printf("NO SOLUTION");
        return 0;
    }
    double minSubsity = -1e9;
    double maxSubsity = 1e9;
    int prea = pre - cost;
    profit[prea] = (a[prea] - cost) * b[prea];
    for (int i = 0; i <= n; ++i)
    {
        profit[i] = (a[i] - cost) * b[i];
        double t = profit[i] - profit[prea];
        if (b[prea] - b[i] < 0)
        {
            maxSubsity = min(maxSubsity, t / double(b[prea] - b[i]));
        }
        else if (b[prea] - b[i] > 0)
        {
            minSubsity = max(minSubsity, t / double(b[prea] - b[i]));
        }
    }
    int minres;
    if (minSubsity > maxSubsity)
    {
        printf("NO SOLUTION");
        return 0;
    }
    else if(minSubsity>0)
    {
        printf("%.0lf",ceil(minSubsity));
    }
    else if(maxSubsity<0)
    {
        printf("%.0lf",floor(maxSubsity));
    }
    else printf("0");

    return 0;
}
