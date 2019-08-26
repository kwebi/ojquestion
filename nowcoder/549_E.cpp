#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>

typedef long long ll;
const int L = 105;
const ll mod = 1e9 + 7;
int n, m, k, s;

struct Matrix
{
    ll a[L][L];
    Matrix() { memset(a, 0, sizeof(a)); }
    Matrix operator*(const Matrix &rhs) const
    {
        Matrix res;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * rhs.a[k][j]) % mod;
        return res;
    }
} G, res;

void fpow(int k)
{
    while (k)
    {
        if (k & 1)
            res = res * G;
        G = G * G;
        k >>= 1;
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G.a[u][v]++;
    }
    for (int i = 1; i <= n; i++)
        res.a[i][i] = 1;

    fpow(k);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        if (i != s)
            sum += res.a[s][i], sum %= mod;
    printf("%lld\n", sum);
    return 0;
}
