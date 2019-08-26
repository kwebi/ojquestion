#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int mod=1e9+7;
const int maxn=1e3+10;
ll comb[maxn][maxn];

void init(){
	for(int i=0;i<=1000;i++)comb[i][0]=1;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=i;j++){
			comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
			comb[i][j]%=mod;
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	init();
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		if(n<m)swap(n,m);
		printf("%I64d\n",comb[n][m]);
	}
	return 0;
}
