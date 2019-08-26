#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

uint64_t fibonacci(LL n)
{
    uint64_t m[2][2] = {1, 1, 1, 0};     // 1次矩阵
    uint64_t result[][2] = {1, 0, 0, 1}; // 单位矩阵
    uint64_t temp[2][2];
    while (n)
    {
        if (n & 1)
        {
            temp[0][0] = result[0][0] * m[0][0] + result[0][1] * m[1][0];
            temp[0][1] = result[0][0] * m[0][1] + result[0][1] * m[1][1];
            temp[1][0] = result[1][0] * m[0][0] + result[1][1] * m[1][0];
            temp[1][1] = result[1][0] * m[0][1] + result[1][1] * m[1][1];
            memcpy(result, temp, sizeof(uint64_t) * 4);
        }
        // 2、4、8...次幂矩阵
        temp[0][0] = m[0][0] * m[0][0] + m[0][1] * m[1][0];
        temp[0][1] = m[0][0] * m[0][1] + m[0][1] * m[1][1];
        temp[1][0] = m[1][0] * m[0][0] + m[1][1] * m[1][0];
        temp[1][1] = m[1][0] * m[0][1] + m[1][1] * m[1][1];
        memcpy(m, temp, sizeof(uint64_t) * 4);
        n >>= 1;
    }
    // result[1][0] * 1 + result[1][1] * 0;
    return result[1][0] * 1;
}
int main()
{
    long long n;
    scanf("%lld", &n);

    LL res1 = fibonacci(n - 1);
    LL res2 = fibonacci(n);
    printf("%lld\n", res2 * res2 - res1 * res1 - res1 * res2);
    return 0;
}
