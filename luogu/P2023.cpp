#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=2e5+5;
int a[N];
int MOD;

#define lc (p << 1)
#define rc (p << 1 | 1)
#define mid ((pl + pr) >> 1)
struct Node {
    ll val=0, mul=1, add=0;
    Node(){}
}t[N<<2];

void build(int p,int pl,int pr){
    if(pl==pr){
        t[p].val=a[pl];
        return;
    }
    build(lc,pl,mid);
    build(rc,mid+1,pr);
    t[p].val = (t[lc].val + t[rc].val) % MOD;
}

void pushdown(int p, int pl, int pr) {
    if (t[p].mul == 1 && t[p].add == 0) return;
    t[lc].val = (t[lc].val * t[p].mul % MOD + (mid - pl + 1) * t[p].add % MOD) % MOD;
    t[rc].val = (t[rc].val * t[p].mul % MOD + (pr - mid) * t[p].add % MOD) % MOD;
    t[lc].mul = t[p].mul * t[lc].mul % MOD;
    t[rc].mul = t[p].mul * t[rc].mul % MOD;
    t[lc].add = (t[lc].add * t[p].mul % MOD + t[p].add) % MOD;
    t[rc].add = (t[rc].add * t[p].mul % MOD + t[p].add) % MOD;
    t[p].mul = 1;
    t[p].add = 0;
}

ll ask(int p, int l, int r, int pl, int pr) {
    if (l > pr || r < pl) return 0;
    if (l <= pl && r >= pr) return t[p].val;
    pushdown(p, pl, pr);
    ll vl = ask(lc, l, r, pl, mid);
    ll vr = ask(rc, l, r, mid + 1, pr);
    return (vl + vr) % MOD;
}

// x' = ax + b
void modify(int p, int l, int r, int a, int b, int pl, int pr) {
    if (l > pr || r < pl) return;
    if (l <= pl && r >= pr) {
        t[p].val = (t[p].val * a % MOD + 1LL * (pr - pl + 1) * b % MOD) % MOD;
        t[p].mul = t[p].mul * a % MOD;
        t[p].add = (t[p].add * a % MOD + b) % MOD;
        return;
    }
    pushdown(p, pl, pr);
    modify(lc, l, r, a, b, pl, mid);
    modify(rc, l, r, a, b, mid + 1, pr);
    t[p].val = (t[lc].val + t[rc].val) % MOD;
}
#undef lc
#undef rc
#undef mid

int main(){
    int n;
    scanf("%d%d",&n,&MOD);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    int m;
    scanf("%d",&m);
    while(m--){
        int t1,l,r,c;
        scanf("%d%d%d",&t1,&l,&r);
        if(t1==1){
            scanf("%d",&c);
            modify(1,l,r,c,0,1,n);
        }else if(t1==2){
            scanf("%d",&c);
            modify(1,l,r,1,c,1,n);
        }else{
            ll ans=ask(1,l,r,1,n);
            printf("%lld\n",ans);
        }
    }
    return 0;
}

