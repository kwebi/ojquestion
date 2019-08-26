#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=3e7+5;
ll dp[N];
ll n,x,y;

int main() {
	cin>>n>>x>>y;
	for(int i=0;i<=3*n;i++)dp[i]=1e18;
	dp[1]=x;
	for(int i=2;i<=n;i++){
		dp[i]=min(dp[i-1]+x,dp[i]);
		if(i%2==0){
			dp[i]=min(dp[i/2]+y,dp[i]);
		}else {
			dp[i]=min(dp[i/2]+x+y,dp[i]);
			dp[i]=min(dp[(i+1)/2]+y+x,dp[i]);
		}
	}
	cout<<dp[n];
	return 0;
}


