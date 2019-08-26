#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=3e5+5;
int size[maxn];
int tsize[maxn];
int dep[maxn];
double cc[maxn];
struct Edge {
	int to,next,w;
} edge[maxn*10];
int head[maxn],tot;
void addEdge(int u,int v,int w) {
	edge[tot].to=v;
	edge[tot].w=w;
	edge[tot].next=head[u];
	head[u]=tot++;
}

int dfs(int u,int p,int d) {
	size[u]=1;
	dep[u]=d;
	for(int i=head[u]; i!=-1; i=edge[i].next) {
		int v=edge[i].to;
		if(v==p)continue;
		size[u]+=dfs(v,u,d+1);
	}
	return size[u];
}

int main() {
	memset(head,-1,sizeof(head));
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; i++) {
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		addEdge(a,b,l);
		addEdge(b,a,l);
	}
	dfs(1,0,0);
	
	for(int i=0; i<tot; i+=2) {
		int v1=edge[i].to;
		int v2=edge[i^1].to;
		tsize[i/2+1]=dep[v2]<dep[v1]?size[v1]:size[v2];
	}
	
	double ans=0;
	for(int i=1; i<n; i++) {
		cc[i]=tsize[i]*2.0*(n-tsize[i])/n/(n-1)*3;
		ans+=cc[i]*edge[(i-1)*2].w;
	}
	
	int q;
	scanf("%d",&q);
	for(int j=1; j<=q; j++) {
		int r,w;
		scanf("%d%d",&r,&w);
		ans-=cc[r]*(edge[(r-1)*2].w-w);
		printf("%.7lf\n",ans);
		edge[(r-1)*2].w=w;
	}
	return 0;
}
