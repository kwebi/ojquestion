#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
char s[210][210];
const int maxn=310;
const int INF=0x3f3f3f3f;
struct Edge{
	int to,next,w,d;//流量和花费
	Edge(){
	}
	Edge(int a,int b,int c,int d):to(a),next(b),w(c),d(d){
	}
}edge[maxn*maxn];
int head[maxn],tot;
pii men[maxn],house[maxn];
int dis[maxn];
bool vis[maxn];
int pre[maxn];

void init(){
	memset(head,-1,sizeof(head));
	tot=0;
}

void addEdge(int u,int v,int w,int d){
	edge[tot]=Edge(v,head[u],w,d);
	head[u]=tot++;
	edge[tot]=Edge(u,head[v],0,-d);
	head[v]=tot++;
}

bool spfa(int s,int t){
	queue<int> que;
	for(int i=s;i<=t;i++){
		dis[i]=INF;
		vis[i]=0;
		pre[i]=-1;
	}
	dis[s]=0;
	vis[s]=1;
	que.push(s);
	while(que.size()){
		int u=que.front();que.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(edge[i].w>0&&dis[v]>dis[u]+edge[i].d){
				dis[v]=dis[u]+edge[i].d;
				pre[v]=i;
				if(!vis[v]){
					vis[v]=1;que.push(v);
				}
			}
		}
	}
	if(pre[t]==-1)return false;
	return true;
}

int mcmf(int s,int t,int& cost){
	int flow=0;
	cost=0;
	while(spfa(s,t)){
		int mi=INF;
		for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
			if(mi>edge[i].w) mi=edge[i].w;
		}
		for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
			edge[i].w-=mi;
			edge[i^1].w+=mi;
			cost+=edge[i].d*mi;
		}
		flow+=mi;
	}
	return flow;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0)break;
		int mc=0,hc=0;
		init();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++){
				if(s[i][j]=='m'){
					mc++;
					men[mc].first=i;men[mc].second=j;
				}else if(s[i][j]=='H'){
					hc++;
					house[hc].first=i;house[hc].second=j;
				}
			}
		}
		for(int i=1;i<=mc;i++){
			addEdge(0,i,1,0);
		}
		for(int i=1;i<=hc;i++){
			addEdge(i+mc,mc+hc+1,1,0);
		}
		for(int i=1;i<=mc;i++){
			for(int j=1;j<=hc;j++){
				int d=abs(men[i].first-house[j].first)+abs(men[i].second-house[j].second);
				addEdge(i,mc+j,1,d);
			}
		}
		int cost;
		mcmf(0,mc+hc+1,cost);
		printf("%d\n",cost);
	}
	return 0;
}
