#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);

    if(n>k){
        n=n%k;
    }
    printf("%lld",min(n,abs(k-n)));
    return 0;
}
