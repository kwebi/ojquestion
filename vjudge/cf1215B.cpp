#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=2e5;
ll a[N];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%I64d",&a[i]);
    }
    ll p1=1;
    ll p2=0;
    ll fg=1;
    for(int i=1; i<=n; i++) {
        if(a[i]<0) {
            fg^=1;
        }
        if(fg==1) {
            p1++;
        } else {
            p2++;
        }
    }
    ll ans=p1*p2;
    printf("%I64d %I64d\n",ans,1LL*n*(n+1)/2-ans);
    return 0;
}

