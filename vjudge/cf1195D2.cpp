#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
int a[maxn];
const int Mod=998244353;


int getLen(int x) {
    int res=0;
    while(x!=0) {
        x/=10;
        res++;
    }
    return res;
}

ll qpow(int x,int y) {
    ll t=x;
    ll ans=1;
    while(y!=0) {
        if(y&1) {
            ans*=t;
            if(ans>=Mod) ans%=Mod;
        }
        t*=t;
        if(t>=Mod)t%=Mod;
        y>>=1;
    }
    return ans;
}

ll mfunc(int x) {
    ll ans=0;
    int t = 0;
    while(x!=0) {
        ans+=(x%10)*qpow(10,t++);
        ans+=(x%10)*qpow(10,t++);
        x/=10;
    }
    return ans%Mod;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    ll ans=0;
    for(int i=0; i<n; i++) {
        ll t=(mfunc(a[i]))%Mod;
        t=t*n%Mod;
        ans=(ans+t)%Mod;
    }
    cout << ans <<endl;
    return 0;
}
