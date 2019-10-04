#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

ll a[105];

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        ll sum=0;
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            if(a[i]<=2048){
                sum+=a[i];
            }
        }
        if(sum>=2048){
            printf("YES\n");
        }else printf("NO\n");
    }
    return 0;
}

