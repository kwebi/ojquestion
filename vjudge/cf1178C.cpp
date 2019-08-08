#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Mod=998244353;

ll pow_m(ll x,ll y){
    ll t=x;
    ll ans=1;
    while(y){
        if(y&1){
            ans=(ans*t)%Mod;
        }
        t = (t*t)%Mod;
        y>>=1;
    }
    return ans%Mod;
}


int main()
{
    int w,h;
    scanf("%d%d",&w,&h);
    ll ans=(4*pow_m(2,w-1))%Mod;
    ans=(ans*pow_m(2,h-1))%Mod;
    cout << ans;
    return 0;
}
