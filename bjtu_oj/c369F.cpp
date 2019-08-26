#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=5e3+7;
double dp[maxn][maxn];
int T[maxn];
double P[maxn];

int main() {
	int n,t;
	scanf("%d%d",&n,&t);
	dp[0][0]=1;
	for(int i=1; i<=n; i++) {
		scanf("%lf%d",&P[i],&T[i]);
		P[i]/=100;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=t; j++) {
			
		}
	}
	double ans=0;
	for(int j=1; j<=n; j++) {
		ans+=dp[t][j]*j;
	}
	printf("%.10lf",ans);
	return 0;
}

