#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=3e5+5;
ll a[N];
ll b[N];
ll f[N][3];

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            f[i][0]=f[i][1]=f[i][2]=1e18;
        }
        for(int i=1;i<=n;i++){
            scanf("%I64d%I64d",&a[i],&b[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=2;j++){
                for(int k=0;k<=2;k++){
                    if(a[i]+j==a[i-1]+k)continue;
                    f[i][j]=min(f[i][j],f[i-1][k]+j*b[i]);
                }
            }
        }
        printf("%I64d\n",min(f[n][0],min(f[n][1],f[n][2])));
    }
    return 0;
}

