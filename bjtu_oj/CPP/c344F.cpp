#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int a[6010];
int par[6010];
vector<int> G[6010];
int f[6010][6010];

void dfs(int r) {
	for(int i=0; i<G[r].size(); i++) {
		if(G[r][i]!=r)
			dfs(G[r][i]);
	}
	for(int i=0;i<G[r].size();i++){
		if(G[r][i]!=r){
			f[r][0]+=max(f[G[r][i]][0],f[G[r][i]][1]);
			f[r][1]+=f[G[r][i]][0];
		}
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		f[i][1]=a[i];
	}
	for(int i=1; i<=n-1; i++) {
		int l,k;
		scanf("%d%d",&l,&k);
		G[k].push_back(l);
		par[l]=k;
	}
	int r=1;
	while(par[r]!=0) r=par[r];
	dfs(r);
	int ans=max(f[r][0],f[r][1]);
	printf("%d\n",ans);
	return 0;
}
