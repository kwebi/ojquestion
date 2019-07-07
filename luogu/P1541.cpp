#include <bits/stdc++.h>
using namespace std;

int a[405];
int b[150];

int dp[41][41][41][41];
int cc[5];


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		cc[b[i]]++;
	}

	dp[0][0][0][0] = a[1];

	for (int j1 = 0; j1 <= cc[1]; j1++) {
		for (int j2 = 0; j2 <= cc[2]; j2++) {
			for (int j3 = 0; j3 <= cc[3]; j3++) {
				for (int j4 = 0; j4 <= cc[4]; j4++) {
					int s=j1+j2*2+j3*3+j4*4;
					if(j1!=0) dp[j1][j2][j3][j4]=max(dp[j1-1][j2][j3][j4]+a[s+1],dp[j1][j2][j3][j4]);
					if(j2!=0) dp[j1][j2][j3][j4]=max(dp[j1][j2-1][j3][j4]+a[s+1],dp[j1][j2][j3][j4]);
					if(j3!=0) dp[j1][j2][j3][j4]=max(dp[j1][j2][j3-1][j4]+a[s+1],dp[j1][j2][j3][j4]);
					if(j4!=0) dp[j1][j2][j3][j4]=max(dp[j1][j2][j3][j4-1]+a[s+1],dp[j1][j2][j3][j4]);
				}
			}
		}
	}

	printf("%d\n", dp[cc[1]][cc[2]][cc[3]][cc[4]]);
	return 0;
}
