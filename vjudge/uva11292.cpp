#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=2e4+5;
int a[N];
int b[N];

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
        }
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        ll ans=0;
        int i,j;
        for(i=1,j=1;i<=n&&j<=m;){
            if(a[i]<=b[j]){
                ans+=b[j];
                i++,j++;
            }else {
                j++;
            }
        }
        if(i==n+1){
            printf("%lld\n",ans);
        }else {
            printf("Loowater is doomed!\n");
        }
    }
    return 0;
}

