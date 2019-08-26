#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=105;
const int INF=1e9;

int dis[maxn];
bool vis[maxn];
int mcost[maxn][maxn];
int po[maxn];
int n,m;
int sum;
int dp[60010];

void dijkstra(int s) {
	for(int i=0; i<=n; i++)dis[i]=INF;
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	while(true) {
		int v=-1;
		for(int u=0; u<=n; u++) {
			if(!vis[u]&&(v==-1||dis[u]<dis[v]))v=u;
		}
		if(v==-1)break;
		vis[v]=1;
		for(int u=0; u<=n; u++) {
			dis[u]=min(dis[u],dis[v]+mcost[u][v]);
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(dp,0,sizeof(dp));
		for(int i=0; i<=101; i++) {
			for(int j=0; j<=101; j++)mcost[i][j]=INF;
			mcost[i][i]=0;
		}
		scanf("%d%d",&n,&m);
		for(int i=1; i<=m; i++) {
			int s,e,c;
			scanf("%d%d%d",&s,&e,&c);
			if(mcost[s][e]>c)
				mcost[s][e]=mcost[e][s]=c;
		}
		sum=0;
		for(int i=1; i<=n; i++) {
			scanf("%d",&po[i]);
			sum+=po[i];
		}
		dijkstra(0);
		ll mx=0;
		for(int i=1; i<=n; i++) {
			if(dis[i]!=INF)mx+=dis[i];
		}

		for(int i=1; i<=n; i++) {
			for(int j=mx; j>=dis[i]; j--) {
				dp[j]=max(dp[j],dp[j-dis[i]]+po[i]);
			}
		}

		int ans=INF;
		for(int j=0; j<=mx; j++) {
			if(dp[j]>sum/2) {
				ans=min(ans,j);
				break;
			}
		}
		if(ans!=INF)
			printf("%d\n",ans);
		else
			printf("impossible\n");
	}
	return 0;
}
