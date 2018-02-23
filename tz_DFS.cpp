#include<cstdio>
using namespace std;

bool dfs(int i, int sum, int n, int k, int a[]) {
    if (i == n) return sum == k;
    if (dfs(i + 1, sum, n, k, a)) return true;
    if (dfs(i + 1, sum + a[i], n, k, a)) return true;
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    int k;
    int j;
    for (j = 0; j < n; j++) {
        scanf("%d", &a[j]);
    }
    scanf("%d", &k);
    if (dfs(0, 0, n, k, a)) printf("Yes\n");
    else printf("No\n");
    return 0;
}