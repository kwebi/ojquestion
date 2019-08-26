#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

int a[105];
int b[105];
int dp[105][105];

int main() {
	int n,m,k,s;
	while(~scanf("%d%d%d%d",&n,&m,&k,&s)) {
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=k; i++) {
			scanf("%d",&a[i]);
			scanf("%d",&b[i]);
		}
		int ans=m;
		for(int i=1;i<=s;i++){
		    for(int j=1;j<=k;j++){
		        for(int t=m;t>=0;t--){
		            dp[i][t]=max(dp[i][t],dp[i-1][t]);
		            if(t>=b[j]){
		                dp[i][t]=max(dp[i][t],dp[i-1][t-b[j]]+a[j]);
                    }
                    if(dp[i][t]>=n)ans=min(ans,t);
                }
            }
        }
        
		if(dp[s][m]<n) {
			printf("-1\n");
		} else {
			printf("%d\n",m-ans);
		}

	}
	return 0;
}
