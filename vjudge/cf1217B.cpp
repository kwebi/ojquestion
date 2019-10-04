#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

ll d[105];
ll h[105];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll n,x;
        scanf("%I64d%I64d",&n,&x);
        bool flag=0;
        ll mx=-1e9;
        int mxi=1;
        ll mxd=-1e9;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&d[i],&h[i]);
            if(d[i]>h[i])flag=1;
            if(d[i]-h[i]>mx||(d[i]-h[i]==mx&&d[i]>d[mxi])){
                mx=d[i]-h[i];
                mxi=i;
            }
            if(d[i]>mxd)mxd=d[i];
        }
        if(flag==0&&x<=mxd){
            printf("1\n");continue;
        }
        if(!flag){
            printf("-1\n");continue;
        }
        int ans=0;
        if(x<=mxd){printf("1\n");continue;}
        if(x>d[mxi]){
            x-=d[mxi];ans++;
            int t=x/(d[mxi]-h[mxi]);
            if(t*(d[mxi]-h[mxi])<x)t++;
            if(t==0&&x>0)t=1;
            if(x<0)t=0;
            ans+=t;
            printf("%d\n",ans);
        }else {
            printf("1\n");
        }
    }
    return 0;
}

