#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int DigitSum(int n);
bool IsPrime(int n);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr;
    for (int i = k; i <= n; i++)
    {
        if (DigitSum(i) == k)
        {
            arr.push_back(i);
        }
    }
    int res = 0;
    for (int v : arr)
    {
        if (IsPrime(v))
        {
            res++;
        }
    }
    printf("%d\n", res);
    return 0;
}

int DigitSum(int n)
{
    int res = 0;
    int t = n;
    while (t >= 1)
    {
        res += t % 10;
        t /= 10;
    }
    return res;
}

bool IsPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
