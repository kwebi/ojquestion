#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e3+5;
const int INF=1e9;
struct Edge{
	int t,c;
	Edge(){
	}
	Edge(int _t,int _c):t(_t),c(_c){
	}
};
vector<Edge> G[maxn];
int dis[maxn];
int T,n;

void dijk(int s){
	for(int i=1;i<=n;i++)dis[i]=INF;
	priority_queue<pii,vector<pii>,greater<pii> > Q;
	dis[s]=0;
	Q.push((pii){0,s});
	while(!Q.empty()){
		pii f=Q.top();Q.pop();
		int u=f.second;
		int c=f.first;
		if(dis[u]<c)continue;
		for(int i=0;i<G[u].size();i++){
			Edge t=G[u][i];
			int v=t.t;
			if(dis[v]>dis[u]+t.c){
				dis[v]=dis[u]+t.c;
				Q.push((pii){
					dis[v],v
				});
			}
		}
	}
}

int main(){
	scanf("%d%d",&T,&n);
	for(int t=1;t<=T;t++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		G[u].push_back(Edge(v,c));
		G[v].push_back(Edge(u,c));
	}
	dijk(n);
	printf("%d",dis[1]);
	
	return 0;
}
