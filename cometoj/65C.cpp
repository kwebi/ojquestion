#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

ll exgcd(ll a,ll b,ll& x,ll& y){
    if(a==0&&b==0)return -1;
    if(b==0){x=1;y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll n;
        scanf("%lld",&n);
        n*=2;
        
    }
    return 0;
}

