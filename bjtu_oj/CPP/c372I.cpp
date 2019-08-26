#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e5+5;
const int DEG=20;
struct Edge1{
	int u,v,w;
}edge[maxn*2];

struct Edge{
	int to,next,w;
}es[maxn*2];
int head[maxn],tol;

int tot=0;
int F[maxn];
map<pii,int> mp;
map<pii,int> mvp;

void addEdge1(int u,int v,int w){
	edge[tot].u=u;
	edge[tot].v=v;
	edge[tot].w=w;
	tot++;
}

void addEdge(int u,int v,int w){
	es[tol].to=v;
	es[tol].next=head[u];
	es[tol].w=w;
	head[u]=tol++;
}

bool cmp(const Edge1& a,const Edge1& b){
	return a.w<b.w;
}

int find(int x){
	if(F[x]==-1)return x;
	return F[x]=find(F[x]);
}

int Kruskal(int n){
	memset(F,-1,sizeof(F));
	sort(edge,edge+tot,cmp);
	ll ans=0;
	int cnt=0;
	for(int i=0;i<tot;i++){
		int u=edge[i].u;
		int v=edge[i].v;
		int w=edge[i].w;
		int t1=find(u);
		int t2=find(v);
		if(t1!=t2){
			ans+=w;
			F[t1]=t2;
			cnt++;
			addEdge(u,v,w);
			addEdge(v,u,w);
			mp[make_pair(u,v)]=cnt;
			mp[make_pair(v,u)]=cnt;
		}
		if(cnt==n-1)break;
	}
	return ans;
}

int fa[maxn][DEG];
int deg[maxn];
int dis[maxn][DEG];

void bfs(int r){
	queue<int> que;
	deg[r]=0;
	fa[r][0]=r;
	que.push(r);
	while(que.size()){
		int tmp=que.front();
		que.pop();
		for(int i=1;i<DEG;i++){
			fa[tmp][i]=fa[fa[tmp][i-1]][i-1];
			dis[tmp][i]=max(dis[tmp][i-1],dis[fa[tmp][i-1]][i-1]);
		}
		for(int i=head[tmp];i!=-1;i=es[i].next){
			int v=es[i].to;
			if(v==fa[tmp][0])continue;
			deg[v]=deg[tmp]+1;
			dis[v][0]=es[i].w;
			fa[v][0]=tmp;
			que.push(v);
		}
	}
}

int LCA(int u,int v){
	if(deg[u]>deg[v])swap(u,v);
	int hu=deg[u],hv=deg[v];
	int tu=u,tv=v;
	int ans=0;
	for(int det=hv-hu,i=0;det;det>>=1,i++){
		if(det&1){
			ans=max(ans,dis[tv][i]);
			tv=fa[tv][i];
		}
	}
	if(tv==tu) return ans;
	for(int i=DEG-1;i>=0;i--){
		if(fa[tu][i]==fa[tv][i])continue;
		ans=max(ans,dis[tu][i]);
		ans=max(ans,dis[tv][i]);
		tu=fa[tu][i];
		tv=fa[tv][i];
	}
	ans=max(ans,max(dis[tu][0],dis[tv][0]));
	return ans;
}

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=r;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addEdge1(a,b,c);
		addEdge1(b,a,c);
		mvp[make_pair(a,b)]=c;
		mvp[make_pair(b,a)]=c;
	}
	ll ans=Kruskal(n);
	bfs(1);
	int q;
	scanf("%d",&q);
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		pii p=make_pair(u,v);
		if(mp.count(p)!=0)printf("%I64d\n",ans);
		else {
			printf("%I64d\n",ans-LCA(u,v)+mvp[p]);
		}
	}
	return 0;
}
