#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const int maxn=2e3+5;
int a[maxn];
int dp[maxn][maxn];


int main() {
	int n,k;
	while(~scanf("%d%d",&n,&k)) {
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=k;j++){
		        dp[i][j]=1e9;
            }
        }

		for(int i=1; i<=n; i++) {
			for(int j=1; j*2<=i&&j<=k; j++) {
				dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(a[i-1]-a[i])*(a[i-1]-a[i]));
			}
		}

		cout<<dp[n][k]<<endl;
	}
	return 0;
}
