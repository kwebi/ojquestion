#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<class T>
T sq(const T& x){return x*x;}

const int mod=1e9+7;

const int N=1e5+7;
ll F[N];

void init(){
    F[0]=F[1]=1;
    for(ll i=2;i<N;i++){
        F[i]=(F[i-1]+F[i-2])%mod;
    }
}

int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    if(n<m)swap(n,m);
    init();
    ll ans=(F[n]+F[m]-1)*2%mod;
    printf("%lld\n",ans);
    return 0;
}
