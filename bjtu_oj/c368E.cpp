#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int maxm=1e6+5;
const int maxn=1e5+5;
int n,m;
struct Edge{
	int to,next,w;
}edge[maxm];
int head[maxn],tot;
int vis[maxn];
bool flag=1;
void addEdge(int u,int v,int w){
	edge[tot].to=v;
	edge[tot].next=head[u];
	edge[tot].w=w;
	head[u]=tot++;
}

void dfs(int u){
	for(int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].to;
		int w=edge[i].w;
		if(vis[v]==-1){
			vis[v]=w==1?vis[u]:vis[u]^1;
			dfs(v);
		}else{
			
			if(w==1&&vis[v]!=vis[u]){
				flag=0;return;
			}
			else if(w==0&&vis[v]==vis[u]){
				flag=0;return;
			}
		}
	}
}

ll pow_m(ll x,ll y,const ll mod){
	ll ret=1;
	ll t=x;
	while(y>0){
		if(y&1){
			ret=(ret*t)%mod;
		}
		t=(t*t)%mod;
		y>>=1;
	}
	return ret%mod;
}

int main(){
	scanf("%d%d",&n,&m);
	memset(vis,-1,sizeof(vis));
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==-1){
			vis[i]=0;
			dfs(i);
			if(flag==0){
				printf("0\n");return 0;
			}
			cnt++;
		}
	}
	printf("%I64d",pow_m(2,cnt-1,mod));
	
	return 0;
}
