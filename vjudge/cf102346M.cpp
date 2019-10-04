#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N=1e5+5;
int n,c,t;
int a[N];

bool judge(ll x) {
    ll tmp=x*t;
    ll sum=0;
    int cnt=0;
    for(int i=1; i<=n;) {
        if(a[i]>tmp)return false;
        sum+=a[i];
        i++;
        if(sum>tmp) {
            sum=0;
            i--;
            cnt++;
        }
        if(cnt>c)return false;
    }
    if(sum>tmp)
        return false;
    else if(sum>0)
        cnt++;
    return cnt<=c;
}

int main() {
    scanf("%d%d%d",&n,&c,&t);
    for(int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    ll r=1e9;
    ll l=0;
    while(r>l) {
        ll mid=(l+r)/2;
        if(judge(mid)) {
            r=mid;
        } else {
            l=mid+1;
        }
    }
    printf("%lld\n",r);
    return 0;
}
