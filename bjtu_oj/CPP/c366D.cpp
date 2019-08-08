#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int a[110];
bool nP[110];
int dp[110][1<<16];
int ans[110][1<<16];
int sta[59];
int res[110];
vector<int> prime;

void dfs(int i,int s){
	if(i==0)return;
	res[i]=ans[i][s];
	dfs(i-1,s^sta[res[i]]);//递归取前一个状态的值
}

void getPri() {
	for(int i=2; i<59; i++) {
		if(!nP[i]) {
			prime.push_back(i);
			for(int j=i*2; j<59; j+=i) {
				nP[j]=1;
			}
		}
	}
}

int getSta(int x) {
	int ret=0;
	for(int i=0; i<prime.size(); i++) {
		if(x%prime[i]==0)ret|=(1<<i);
	}
	return ret;
}


int main() {
	getPri();
	memset(dp,INF,sizeof(dp));
	memset(ans,-1,sizeof(ans));
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=2; i<59; i++) {
		sta[i]=getSta(i);
	}
	int mx=(1<<16);
	dp[0][0]=ans[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<mx;j++){
			if(ans[i][j]==-1)continue;
			for(int k=1;k<59;k++){
				if(j&sta[k])continue;//互素
				int s=j|sta[k];//下一个状态
				if(ans[i+1][s]==-1||dp[i][j]+abs(k-a[i+1])<dp[i+1][s]){
					dp[i+1][s]=dp[i][j]+abs(k-a[i+1]);
					ans[i+1][s]=k;
				}
			}
		}
	}
	int mi=INF,t=0;
	for(int i=0;i<mx;i++){
		if(dp[n][i]<mi){
			mi=dp[n][i];
			t=i;
		}
	}
	dfs(n,t);
	for(int i=1;i<=n;i++){
		printf("%d ",res[i]);
	}

	return 0;
}

