#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
const int INF=1e9;

struct Node {
	int s,t,c;
} a[maxn];

struct Edge {
	int from,to,cap,flow,cost,id;
};

struct MCMF {
	int n;
	vector<Edge> es;
	vector<int> G[maxn];
	int inq[maxn];
	int dis[maxn];
	int pre[maxn];
	int cc[maxn];
	void init(int n) {
		this->n=n;
		for(int i=0; i<=n; i++)G[i].clear();
		es.clear();
	}

	void addEdge(int f,int t,int cap,int cost,int id=0) {
		es.push_back((Edge) {
			f,t,cap,0,cost,id
		});
		es.push_back((Edge) {
			t,f,0,0,-cost,id
		});
		int m=es.size();
		G[f].push_back(m-2);
		G[t].push_back(m-1);
	}

	bool spfa(int s,int t,int &flow,int& cost) {
		for(int i=0; i<=n; i++) dis[i]=-INF;
		memset(inq,0,sizeof(inq));
		dis[s]=0;
		inq[s]=1;
		pre[s]=0;
		cc[s]=INF;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty()) {
			int u=Q.front();
			Q.pop();
			inq[u]=0;
			for(int i=0; i<G[u].size(); i++) {
				Edge& e= es[G[u][i]];
				if(e.cap>e.flow && dis[e.to]<dis[u]+e.cost) {
					dis[e.to]=dis[u]+e.cost;
					pre[e.to]=G[u][i];
					cc[e.to]=min(cc[u],e.cap-e.flow);
					if(!inq[e.to]) {
						Q.push(e.to);
						inq[e.to]=1;
					}
				}
			}
		}
		if(dis[t]==-INF) return false;
		flow+=cc[t];
		cost+=dis[t]*cc[t];
		int u=t;
		while(u!=s) {
			es[pre[u]].flow+=cc[t];
			es[pre[u]^1].flow-=cc[t];
			u=es[pre[u]].from;
		}
		
		return true;
	}
	int minCost(int s,int t) {
		int flow=0,cost=0;
		while(spfa(s,t,flow,cost));
		return cost;
	}
} mcmf;

map<int,int> mp;
bool res[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> mtime;
	for(int i=1; i<=n; i++) {
		cin>>a[i].s>>a[i].t>>a[i].c;
		a[i].t+=a[i].s;
		mp[a[i].s]=0;
		mp[a[i].t]=0;
	}
	int cnt=0;
	for(auto &e:mp) e.second=++cnt;
	for(int i=1;i<=n;i++){
		int x=mp[a[i].s];
		int y=mp[a[i].t];
		a[i].s=x;
		a[i].t=y;
	}
	mcmf.init(cnt+1);
	for(int i=0;i<=cnt;i++){
		mcmf.addEdge(i,i+1,k,0);
	}
	for(int i=1;i<=n;i++){
		mcmf.addEdge(a[i].s,a[i].t,1,a[i].c,i);
	}
	mcmf.minCost(0,cnt+1);
	for(int i=2;i<mcmf.es.size();i+=2){
		Edge& e=mcmf.es[i];
		if(e.flow==e.cap&&e.id!=0){
			res[e.id]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<res[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}

