#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=3e3+5;
struct Edge{
    int t,next,c;
}edge[N];
int head[N],tot;
int mon[N];
int dis[N];
int n,m;

void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}

void addEdge(int u,int v,int cost){
    edge[tot].t=v;
    edge[tot].c=cost;
    edge[tot].next=head[u];
    head[u]=tot++;
}

void dfs(int u,int pre,int d){
    if(u<=n&&u>=n-m+1){
        dis[u]=d;return;
    }
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].t;
        if(v==pre)continue;
        dfs(v,u,d+edge[i].c);
    }
}

int a[N],b[N],cnt;
int f[N][N];

int main(){
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n-m;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int aj,cj;
            scanf("%d%d",&aj,&cj);
            addEdge(k,aj,cj);
        }
    }

    dfs(1,0,0);
    for(int i=n-m+1;i<=n;i++){
        scanf("%d",&mon[i]);
        
    }
    
    printf("%d\n",ans+f[cnt][lt]);
    return 0;
}

