#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll dp[1<<18][105];
bool vis[10];
vector<int> a;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	while(n>0){
		int t=n%10;
		a.push_back(t);
		n/=10;
	}
	int l=a.size();
	dp[0][0]=1;
	for(int i=0;i<(1<<l);i++){
		for(int j=0;j<m;j++){
			if(dp[i][j]==0)continue;
			memset(vis,0,sizeof(vis));
			for(int k=0;k<l;k++){
				if((1<<k)&(i))continue;
				if(i==0&&a[k]==0)continue;
				if(vis[a[k]])continue;
				vis[a[k]]=1;
				dp[i|(1<<k)][(j*10+a[k])%m]+=dp[i][j];
			}
		}
	}
	cout<<dp[(1<<l)-1][0]<<endl;
	return 0;
}

