#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[50005];
int n, m;

void print() {
    for (ll i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

ll C(int x) {
    return 1ll * x * (x - 1) / 2;
}

void countNum(int x) {
    while (m > C(x)) x++;
    if (m == C(x)) {
        sort(a + n - x, a + n, greater<int>());
    } else if (m < C(x)) {
        sort(a + n - x + 1, a + n, greater<int>());
        int t = C(x - 1);
        int l = m - t;
        swap(a[n - x], a[n - l]);
        sort(a + n - x + 1, a + n, greater<int>());
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    countNum(1);
    print();
    return 0;
}
