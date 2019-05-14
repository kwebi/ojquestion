#include <cmath>
#include <stdio.h>
#include <climits>
#include <string.h>
#include <iostream>
using namespace std;

double a[20][2];
double deca[20][20];
bool vis[20] = {0};
int n;
double tmpans = 0;
double ans = 1e9;
double decent(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void dfs(int k, int step)
{
    if (tmpans > ans)
        return;
    if (step == n)
    {
        ans = ans <= tmpans ? ans : tmpans;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            double d;
            if (deca[k][i] >= 0)
            {
                d = deca[k][i];
            }
            else if (deca[i][k] >= 0)
            {
                d = deca[i][k];
            }
            else
            {
                d = decent(a[k][0], a[k][1], a[i][0], a[i][1]);
                deca[k][i] = d;
                deca[i][k] = d;
            }

            tmpans += d;
            vis[i] = 1;
            dfs(i, step + 1);
            tmpans -= d;
            vis[i] = 0;
        }
    }
}

int main()
{
    memset(deca, -1, sizeof(deca));
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    if (n == 0)
        return puts("0.00\n"), 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i][0] >> a[i][1];
    }
    a[0][0] = 0;
    a[0][1] = 0;

    dfs(0, 0);
    printf("%0.2lf\n", ans);
    return 0;
}
