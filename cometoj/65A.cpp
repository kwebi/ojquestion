#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x) << 1)
#define RC(x) ((x) << 1 | 1)

const int N = 1e3 + 5;
char s[N][N];
char t[] = "acpty";

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        int len = strlen(s[i]);
        int tmp = 4;
        int j=len-1;
        while (tmp >= 0 && j >= 0 && s[i][j] == t[tmp]) {
            j--, tmp--;
        }
        if (tmp < 0) {
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
