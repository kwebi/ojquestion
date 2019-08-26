#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=410;
const int INF=0x3f3f3f3f;
struct Edge{
	int to,next,w;
	Edge(){
	}
	Edge(int a,int b,int c):to(a),next(b),w(c){
	}
}edge[maxn*maxn];
int head[maxn],tot;
int dep[maxn],cur[maxn];

void init(){
	memset(head,-1,sizeof(head));
	tot=0;
}

void addEdge(int u,int v,int w){
	edge[tot]=Edge(v,head[u],w);
	head[u]=tot++;
	edge[tot]=Edge(u,head[v],0);
	head[v]=tot++;
}

bool bfs(int s,int t){
	memset(dep,-1,sizeof(dep));
	for(int i=s;i<=t;i++)cur[i]=head[i];
	queue<int> que;
	dep[s]=0;
	que.push(s);
	while(que.size()){
		int u=que.front();que.pop();
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].w>0&&dep[v]==-1){
				dep[v]=dep[u]+1;
				que.push(v);
			}
		}
	}
	if(dep[t]!=-1)return true;
	return false;
}

int dfs(int now,int t,int limit){
	if(!limit||now==t)return limit;
	int flow=0,f;
	for(int i=cur[now];i!=-1;i=edge[i].next){
		cur[now]=i;
		int v=edge[i].to;
		if(dep[v]==dep[now]+1&&(f=dfs(v,t,min(limit,edge[i].w)))){
			flow+=f;
			limit-=f;
			edge[i].w-=f;
			edge[i^1].w+=f;
			if(!limit)break;
		}
	}
	return flow;
}

int dinic(int s,int t){
	int maxflow=0;
	while(bfs(s,t)){
		
		maxflow+=dfs(s,t,INF);
	}
	return maxflow;
}

int main(){
	init();
	int N,F,D;
	scanf("%d%d%d",&N,&F,&D);
	int nf=2*N+F;
	int nfd=2*N+F+D;
	for(int i=1;i<=F;i++){
		addEdge(0,2*N+i,1);
	}
	for(int i=1;i<=D;i++){
		addEdge(nf+i,nfd+1,1);
	}
	for(int i=1;i<=N;i++){
		int f,d;
		scanf("%d%d",&f,&d);
		for(int j=1;j<=f;j++){
			int t;scanf("%d",&t);
			addEdge(2*N+t,i,1);
		}
		addEdge(i,N+i,1);
		for(int j=1;j<=d;j++){
			int t;scanf("%d",&t);
			addEdge(N+i,nf+t,1);
		}
	}
	printf("%d",dinic(0,nfd+1));
	return 0;
}
