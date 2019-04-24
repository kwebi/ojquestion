//贪心
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;
int n, a[10001], average, sum, ans = 0;
void divide()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < average) //如果当前数小于平均值
        {
            int need = average - a[i]; //需要量=平均值-当前数
            ans++;                     //答案数+1
            a[i + 1] -= need;          //从下一堆中取出需要量给当前堆
        }
        if (a[i] > average) //如果当前数大于平均值
        {
            int rich = a[i] - average; //剩余量=当前数-平均数
            ans++;                     //答案数+1
            a[i + 1] += rich;          //把剩余的取出，加到下一堆中
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    average = sum / n; //求平均值
    divide();
    cout << ans;
    return 0;
}