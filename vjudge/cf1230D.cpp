#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

ll a[7010];
ll b[7010];
unordered_map<ll,ll> mp;
unordered_map<ll,ll> rmp;

int belong(ll a,ll b){
    int r1=0,r2=0;
    for(int i=0;i<60;i++){
        ll x=a&(1LL<<i);
        ll y=b&(1LL<<i);
        if(x&&!y) r2=1;
        if(!x&&y) r1=1;
    }
    if(!r1&&r2)return 1;
    if(r1&&!r2)return -1;
    if(!r1&&!r2)return 0;
    return -2;
}

vector<ll> eq;
vector<ll> req;

int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        mp[a[i]]+=b[i];
        rmp[a[i]]++;
    }
    for(auto e:rmp){
        if(e.second>=2){
            ans+=mp[e.first];
            eq.push_back(e.first);
        }else req.push_back(e.first);
    }
    for(int i=0;i<req.size();i++){
        for(int j=0;j<eq.size();j++){
            if(~eq[j]&req[i]){
            }else {
                ans+=mp[req[i]];
                break;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

