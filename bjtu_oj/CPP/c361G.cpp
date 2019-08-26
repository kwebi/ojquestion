#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

//适用于正负整数
template <class T>
inline bool scan_d(T &ret) {
	char c;
	int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}

inline void out(int x) {
	if(x>9) out(x/10);
	putchar(x%10+'0');
}

const int maxn=2e4+5;
const int INF=1e9+7;
int a[maxn];
int b[maxn];

struct Edge {
	int to,next,w;
	Edge() {}
	Edge(int a,int b,int c):to(a),next(b),w(c) {}
} edge[maxn*maxn/10];
int head[maxn],tot;
int dep[maxn],cur[maxn];
void init() {
	memset(head,-1,sizeof(head));
	tot=0;
}

void addEdge(int u,int v,int w) {
	edge[tot]=Edge(v,head[u],w);
	head[u]=tot++;
	edge[tot]=Edge(u,head[v],0);
	head[v]=tot++;
}

bool bfs(int s,int t) {
	memset(dep,-1,sizeof(dep));
	queue<int> q;
	for(int i=s; i<=t; i++) {
		cur[i]=head[i];
	}
	dep[s]=0;
	q.push(s);
	while(q.size()) {
		int u=q.front();
		q.pop();
		for(int i=head[u]; i!=-1; i=edge[i].next) {
			int v=edge[i].to;
			if(edge[i].w>0&&dep[v]==-1) {
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	if(dep[t]==-1)return false;
	return true;
}

int dfs(int now,int t,int limit) {
	if(!limit||now==t)return limit;
	int flow=0,f;
	for(int i=cur[now]; i!=-1; i=edge[i].next) {
		cur[now]=i;
		int v=edge[i].to;
		if(dep[v]==dep[now]+1&&(f=dfs(v,t,min(limit,edge[i].w)))) {
			flow+=f;
			limit-=f;
			edge[i].w-=f;
			edge[i^1].w+=f;
			if(!limit)break;
		}
	}
	return flow;
}

int dinic(int s,int t) {
	int maxflow=0;
	while(bfs(s,t)) {
		maxflow+=dfs(s,t,INF);
	}
	return maxflow;
}

int main() {
	init();
	int n,m;
	scan_d(n);
	scan_d(m);
	int s=0,t=n+1;
	for(int i=1; i<=n; i++) {
		scan_d(a[i]);
		scan_d(b[i]);
		addEdge(s,i,a[i]);
		addEdge(i,t,b[i]);
	}
	for(int i=1; i<=m; i++) {
		int a,b,w;
		scan_d(a);
		scan_d(b);
		scan_d(w);
		addEdge(a,b,w);
		addEdge(b,a,w);
	}
	
	printf("%d",dinic(s,t));

	return 0;
}
