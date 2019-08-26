#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn=1e5+7;

int prof[maxn];
vector<int> G[maxn];
int ind[maxn];
ll ans=-1e18;
const ll INF=1e18;
ll dis[maxn];
int n,m;

void solve() {
	for(int i=1;i<=n;i++)dis[i]=-INF;
	queue<int> Q;
	for(int i=1; i<=n; i++) {
		if(ind[i]==0) {
			Q.push(i);
			dis[i]=prof[i];
		}
	}

	while(!Q.empty()) {
		int u=Q.front();
		Q.pop();
		if(G[u].empty()){
			ans=max(ans,dis[u]);
		}
		for(int i=0; i<G[u].size(); i++) {
			int v=G[u][i];
			ind[v]--;
			dis[v]=max(dis[u]+prof[v],dis[v]);
			if(ind[v]==0){
				Q.push(v);
			}
		}
	}
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		ans=-1e18;
		memset(ind,0,sizeof(ind));
		for(int i=0; i<=n; i++)G[i].clear();
		for(int i=1; i<=n; i++)scanf("%d",&prof[i]);
		for(int i=1; i<=m; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			ind[y]++;
		}
		solve();

		printf("%I64d\n",ans);
	}
	return 0;
}
