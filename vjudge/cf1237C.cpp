#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<class T>
T sq(const T& x){return x*x;}

const int N=2e5+7;
ll x[N];
ll y[N];
ll z[N];
bool vis[N];

ll s2(ll x){
    return x*x;
}
 
ll dis(int i,int j){
    return s2(x[i]-x[j])+s2(y[i]-y[j])+s2(z[i]-z[j]);
}
vector<pii> ans;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        int mi=i+1;
        ll d=1e18;
        for(int j=i+1;j<=n;j++){
            if(vis[j])continue;
            ll t=dis(i,j);
            if(t<d){
                d=t;
                mi=j;
            }
        }
        vis[mi]=1;
        ans.push_back(pii(i,mi));
    }
    for(int i=0;i<ans.size();i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}