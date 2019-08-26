#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N=2e5+5;
const int mod=10007;
char s[N];
int Next[N];
int dp[N];

void kmp_pre(char x[],int m,int next[]){
	int i,j;
	j=next[0]=-1;
	i=0;
	while(i<m){
		while(j!=-1&&x[i]!=x[j])j=next[j];
		next[++i]=++j;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(Next,0,sizeof(Next));
		int n;
		scanf("%d%s",&n,s);
		kmp_pre(s,n,Next);
		int ans=0;
		for(int i=1;i<=n;i++){
			dp[i]=(dp[Next[i]]+1)%mod;
			ans=(ans+dp[i])%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}


