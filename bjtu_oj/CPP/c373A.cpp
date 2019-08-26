#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+5;
int a[maxn];

struct Edge{
	int to,next,w;
}edge[maxn*20];
int head[maxn],tot;
int dis[maxn];
int vis[maxn];
const int INF=1e9;
int n;
void addEdge(int u,int v,int w){
	edge[tot].to=v;
	edge[tot].next=head[u];
	edge[tot].w=w;
	head[u]=tot++;
}

void dijk(int s){
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>> Q;
	Q.push(make_pair(0,s));
	while(Q.size()){
		pii t=Q.top();Q.pop();
		if(vis[t.second])continue;
		int u=t.second;
		vis[u]=1;
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(!vis[v]&&dis[v]>dis[u]+edge[i].w){
				dis[v]=dis[u]+edge[i].w;
				Q.push(make_pair(dis[v],v));
			}
		}
	}
}


int main(){
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		addEdge(i,i+1,1);
		addEdge(i+1,i,1);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		addEdge(i,a[i],1);
	}
	dijk(1);
	for(int i=1;i<=n;i++){
		printf("%d ",dis[i]);
	}
	
	return 0;
}
