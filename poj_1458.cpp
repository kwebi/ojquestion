#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char X[1005];
char Y[1005];
int dp[1005][1005];
int main() {
    while(cin >> X >> Y) {
        memset(dp, 0, sizeof(dp));
        int n = strlen(X);
        int m = strlen(Y);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (X[i] == Y[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}