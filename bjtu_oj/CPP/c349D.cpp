#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+5;
typedef long long ll;

struct edge {
    ll t,c;
};

struct Node {
    long long d, id;
    Node() {}
    Node(long long d, ll id) : d(d), id(id) {}
    bool operator < (const Node& rhs) const {
        return d > rhs.d;
    }
};

const long long INF=5e18;
vector<edge> G[maxn];
ll trn[maxn];
bool vis[maxn];
int isTr[maxn];
long long dis[maxn];
ll n,m,k;
int ans=0;

void dijkstra(int s) {
    memset(vis,0,sizeof(vis));
    priority_queue<Node> Q;
    for(ll i=1; i<=n; i++){
        dis[i]=INF;
        if(trn[i]!=0){
            dis[i]=trn[i];
            Q.push({trn[i],i});
        }
    }
    dis[s]=0;

    Q.push({0,s});
    while(!Q.empty()) {
        Node u=Q.top();
        Q.pop();
        if(vis[u.id]) continue;
        vis[u.id]=1;
        for(int i=0; i<G[u.id].size(); i++) {
            ll to=G[u.id][i].t;
            ll c=G[u.id][i].c;
            if(!vis[to]&&u.d+c<=dis[to]) {
                if(isTr[to]==1) {
                    isTr[to]=-1;
                    ans++;
                }
                if(!vis[to]&&u.d+c<dis[to]) {
                    dis[to]=u.d+c;
                    Q.push({dis[to],to});
                }
            }
        }
    }
}

int main() {
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++) {
        ll u,v,x;
        scanf("%I64d%I64d%I64d",&u,&v,&x);
        /*
        for(int j=0; j<G[u].size(); j++) {
            if(G[u][j].t==v) {
                G[u][j].c=min(G[u][j].c,x);
                break;
            }
        }
        bool f=0;
        for(int j=0; j<G[v].size(); j++) {
            if(G[v][j].t==u) {
                G[v][j].c=min(G[v][j].c,x);
                f=1;
                break;
            }
        }
        if(f) continue;
        */
        G[u].push_back({v,x});
        G[v].push_back({u,x});
    }
    for(int i=1; i<=k; i++) {
        ll s,y;
        scanf("%I64d%I64d",&s,&y);
        if(trn[s]!=0) {
            trn[s]=min(trn[s],y);
            ans++;
        } else {
            isTr[s]=1;
            trn[s]=y;
        }
    }
    
    dijkstra(1);
    cout <<ans<<endl;
    return 0;
}
