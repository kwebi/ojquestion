#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=2e5+5;
int a[N];
int b[N];
int n,m,mod;

ll pow_m(ll x,ll y){
    ll ret=1;
    ll t=x;
    while(y>0){
        if(y&1)ret=(ret*t)%mod;
        t=(t*t)%mod;
        y>>=1;
    }
    return ret%mod;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&mod);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]=pow_m(a[i],a[i]);
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
        }
        sort(b+1,b+1+m);
        int i=1,j=1;
        int ans=0;
        while(i<=m&&j<=n){
            if(a[j]>=b[i]){
                j++,i++;
                ans++;
            }else{
                j++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

