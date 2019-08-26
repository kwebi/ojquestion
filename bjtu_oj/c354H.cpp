#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=3e4+7;
const int INF=1e9;
struct Edge {
	int v,c;
	int next;
	Edge(){
	}
	Edge(int a,int b):v(a),c(b) {
	}
}es[maxn*10];
int head[maxn];
int cnt;

bool vis[maxn];
int dis[maxn];
int n,m;

void addEdge(int u,int v,int c){
	es[cnt]=Edge(v,c);
	es[cnt].next=head[u];
	head[u]=cnt++;
}

void dijkstra(int s) {
	for(int i=1; i<=n; i++)dis[i]=INF;
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > Q;
	Q.push(make_pair(0,s));
	while(!Q.empty()) {
		pii t=Q.top();
		Q.pop();
		int c=t.first;
		int u=t.second;
		if(dis[u]<c)continue;
		for(int i=head[u]; i!=-1; i=es[i].next) {
			Edge e=es[i];
			if(dis[e.v]>dis[u]+e.c) {
				dis[e.v]=dis[u]+e.c;
				Q.push(make_pair(dis[e.v],e.v));
			}
		}
	}
}


int main() {
	cnt=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addEdge(b,a,c);
	}
	dijkstra(n);
	printf("%d\n",dis[1]);
	return 0;
}
