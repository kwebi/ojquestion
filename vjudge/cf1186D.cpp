#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

double a[maxn];
int cc[maxn];

int main()
{
    int n;
    vector<int> res;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
        int d = floor(abs(a[i]));
        if (a[i] >= 0) {
            double t = a[i] - d;
            if (t < 1e-5) {
                cc[i - 1] = -1;
                res.push_back(floor(a[i]));
                continue;
            }
            if (t - 0.5 > 1e-6) {
                cc[i - 1] = 1;
                res.push_back(ceil(a[i]));
            } else {
                res.push_back(floor(a[i]));
            }
        } else {
            double t = a[i] + d;
            t = abs(t);
            if (t < 1e-5) {
                cc[i - 1] = -1;
                res.push_back(floor(a[i]));
                continue;
            }
            if (t - 0.5 > 1e-6) {
                res.push_back(floor(a[i]));
            } else {
                cc[i - 1] = 1;
                res.push_back(ceil(a[i]));
            }
        }
    }
    long long ans = 0;
    for (auto e : res) {
        ans += e;
    }

    if (ans > 0) {
        for (int i = 0; i < n; i++) {
            if (ans == 0)
                break;
            if (cc[i] == 1) {
                res[i]--;
                cc[i] = 0;
                ans--;
            }
        }
    }
    if (ans < 0) {
        for (int i = 0; i < n; i++) {
            if (ans == 0)
                break;
            if (cc[i] == 0) {
                res[i]++;
                cc[i] = 1;
                ans++;
            }
        }
    }

    for (auto e : res) {
        printf("%d\n", e);
    }

    return 0;
}
