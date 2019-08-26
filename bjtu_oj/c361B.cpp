#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
const int maxn=300;
const int INF=0x3f3f3f3f;
struct Edge{
	int to,next,cap;
}edge[maxn*maxn];
int head[maxn],tot;
int dep[maxn],cur[maxn];

void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c){
	edge[tot].to=v;edge[tot].cap=c;
	edge[tot].next=head[u];head[u]=tot++;
	edge[tot].to=u;edge[tot].cap=0;
	edge[tot].next=head[v];head[v]=tot++;
}


bool bfs(int s,int t){
	memset(dep,-1,sizeof(dep));
	for(int i=1;i<=n;i++)cur[i]=head[i];
	queue<int> que;
	dep[s]=0;
	que.push(s);
	while(que.size()){
		int u=que.front();que.pop();
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].cap>0&&dep[v]==-1){
				dep[v]=dep[u]+1;
				que.push(v);
			}
		}
	}
	if(dep[t]!=-1)return true;
	//printf("%d",dep[t]);
	return false;
}

int dfs(int now,int t,int limit){
	if(!limit||now==t)return limit;
	int flow=0,f;
	
	for(int i=cur[now];i!=-1;i=edge[i].next){
		cur[now]=i;
		int v=edge[i].to;
		if(dep[v]==dep[now]+1&&(f=dfs(v,t,min(limit,edge[i].cap)))){
			flow+=f;
			limit-=f;
			edge[i].cap-=f;
			edge[i^1].cap+=f;
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
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=n;i++){
			int s,e,c;
			scanf("%d%d%d",&s,&e,&c);
			addEdge(s,e,c);
		}
		printf("%d\n",dinic(1,m));
	}
	return 0;
}
