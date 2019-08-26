#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
vector<int> G[maxn];
int a[maxn];
int b[maxn];
vector<int> ans;

void dfs(int p,int x,int o,int e){//o,e 奇数层和偶数层变换的奇偶
	if((a[x]^o)!=b[x]){
		ans.push_back(x);
		o=!o;
	}
	for(int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if(v!=p){
			dfs(x,v,e,o);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	dfs(0,1,0,0);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d\n",ans[i]);
	}
	
	return 0;
}

