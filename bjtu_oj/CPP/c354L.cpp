#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=105;
const int INF=1e9;

struct Edge {
	int v,c,next;
} es[maxn*maxn];
struct Node {
	int val,lev;
};
int head[maxn];
int cnt=0;
Node ob[maxn];
int dis[maxn];
int vis[maxn];
int m,n;
int mxl,mil;

int mabs(int x) {
	return x<0?-x:x;
}

void dijkstra(int s) {
	for(int i=0; i<=n; i++)dis[i]=INF;
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > Q;
	Q.push(make_pair(0,s));
	while(!Q.empty()) {
		pii f=Q.top();
		Q.pop();
		int u=f.second;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u]; i!=-1; i=es[i].next) {
			Edge& e=es[i];
			if(ob[e.v].lev<mil||ob[e.v].lev>mxl)continue;
			if(dis[e.v]>dis[u]+e.c) {
				dis[e.v]=dis[u]+e.c;
				Q.push(make_pair(dis[e.v],e.v));
			}
		}
	}
}

void addEdge(int u,int v,int c) {
	es[cnt].v=v;
	es[cnt].c=c;
	es[cnt].next=head[u];
	head[u]=cnt++;
}

int main() {
	cnt=0;
	int ncnt=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&m,&n);
	for(int i=1; i<=n; i++) {
		int p,l,x;
		scanf("%d%d%d",&p,&l,&x);
		++ncnt;
		ob[ncnt].val=p;
		ob[ncnt].lev=l;
		for(int j=1; j<=x; j++) {
			int t,v;
			scanf("%d%d",&t,&v);
			addEdge(ncnt,t,v);
		}
	}

	int ans=INF;
	for(int j=ob[1].lev-m; j<=ob[1].lev; j++) {
		mil=j;
		mxl=j+m;
		dijkstra(1);
		for(int i=1; i<=n; i++) {
			if(dis[i]!=INF) {
				ans=min(ans,dis[i]+ob[i].val);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

