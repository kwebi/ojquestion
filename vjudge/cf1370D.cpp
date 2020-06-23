#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 10;

int a[N];
int n, k;

bool check(int x)
{
    int tol = 0;
    for (int i = 0; i < n; i++) {
        if (tol & 1) {
            if (a[i] <= x) {
                tol++;
            }
        } else {
            tol++;
        }
        if (tol == k)
            return true;
    }

    tol = 0;
    for (int i = 0; i < n; i++) {
        if (tol % 2 == 0) {
            if (a[i] <= x)
                tol++;
        } else {
            tol++;
        }
        if (tol == k)
            return true;
    }
    return false;
}

int main()
{

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ed = 2e9;
    int bg = 1;
    while (ed > bg) {
        int mid = (ed + bg) / 2;
        // cout << mid << endl;
        if (check(mid)) {
            ed = mid;
        } else {
            bg = mid + 1;
        }
    }
    printf("%d\n", ed);
    return 0;
}