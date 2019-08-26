#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=2e5+5;
string s;

ll pow_m(ll x,ll y,ll mod){
    ll t=x;
    ll ret=1;
    while(y>0){
        if(y&1){
            ret=(ret*t)%mod;
        }
        t=(t*t)%mod;
        y>>=1;
    }
    return ret%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int m;
    cin>>m;
    ll slen=s.size();
    ll x=0;
    for(int i=0;i<slen;i++){
        x=(x*10+s[i]-'0')%m;
    }
    ll ten=pow_m(10,slen-1,m);
    ll ans=x;
    for(ll i=0;i<slen-1;i++){
        x=(x+m-ten*(s[i]-'0')%m)%m;
        x=(x*10+s[i]-'0')%m;
        if(s[i+1]!='0'){
            ans=min(ans,x);
        }
    }
    cout<<ans<<endl;
    return 0;
}

