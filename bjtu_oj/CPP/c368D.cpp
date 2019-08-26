#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=4e6+5;
int a[maxn];
int dp[1<<22];

int main() {
	memset(dp,-1,sizeof(dp));
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	
	for(int i=1; i<=n; i++) {
		dp[a[i]]=a[i];
	}
	int N=(1<<22)-1;
	for(int i=0; i<=N; i++) {
		if(dp[i]!=-1)continue;
		for(int j=0; j<22; j++) {
			if(i&(1<<j)&&dp[i-(1<<j)]!=-1) {
				dp[i]=dp[i-(1<<j)];
			}
		}
	}
	for(int i=1; i<=n; i++) {
		printf("%d ",dp[N^a[i]]);
	}
	return 0;
}
