#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+7;
vector<int> G[maxn];
int cc[maxn];
int vis[maxn];
vector<int> ans;

void dfs(int u,int pre) {
	vis[u]=1;
	ans.push_back(u);
	cc[u]^=1;
	for(int j=0; j<G[u].size(); j++) {
		int v=G[u][j];
		if(!vis[v]) {
			dfs(v,u);
			ans.push_back(u);
			cc[u]^=1;
		}
	}
	if(cc[u]&&pre!=-1) {
		ans.push_back(pre);
		ans.push_back(u);
		cc[pre]^=1;
		cc[u]^=1;
	}
	if(cc[u]&&pre==-1){
		ans.pop_back();
		cc[u]^=1;
	}
}


int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&cc[i]);
	}
	for(int i=1; i<=n; i++) {
		if(cc[i]) {
			dfs(i,-1);
			break;
		}
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]&&cc[i]) {
			printf("-1");
			return 0;
		}
	}
	
	printf("%d\n",ans.size());
	for(int i=0; i<ans.size(); i++) {
		printf("%d ",ans[i]);
	}
	return 0;
}

