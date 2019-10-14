#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N=1e6+7;
vector<int> G[N];
int val[N],rk[N];

ll Tr[N];
ll pv[N];
ll ans[N];
int mxrk;

int lowbit(int x){return x&-x;}

void update(int o,int v,int n){
    for(int i=o;i<=n;i+=lowbit(i))Tr[i]+=v;
}

ll query(int o){
    ll ret=0;
    for(int i=o;i;i-=lowbit(i))ret+=Tr[i];
    return ret;
}

void dfs(int u){
    pv[u]=query(rk[u]-1);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        update(rk[v],val[v],mxrk);
        dfs(v);
    }
    ans[u]=query(rk[u]-1)-pv[u];
}

int main(){
    int n;
    scanf("%d",&n);
    rk[0]=1;
    for(int i=1;i<=n;i++){
        int m;
        scanf("%d%d%d",&m,&rk[i],&val[i]);
        mxrk=max(mxrk,rk[i]);
        m=m==-1?0:m;
        G[m].push_back(i);
    }
    dfs(0);
    for(int i=1;i<=n;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}

