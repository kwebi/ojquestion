#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int m,n,k;

struct Cir{
    ll x,y,s;
};

Cir a[1010];

int par[1010];

int findp(int x){
    return x==par[x]?x:par[x]=findp(par[x]);
}

bool same(int x,int y){
    x=findp(x);
    y=findp(y);
    return x==y;
}

void unite(int x,int y){
    x=findp(x);
    y=findp(y);
    if(x<y)swap(x,y);
    if(x!=y)par[x]=y;
}

bool isQ(int i,int j){
    ll t1=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
    ll t2=(a[i].s+a[j].s)*(a[i].s+a[j].s);
    return t1<=t2;
}

int main(){
    for(int i=0;i<1009;i++){
        par[i]=i;
    }
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].s);
    }
    for(int i=1;i<=k;i++){
        for(int j=i+1;j<=k;j++){
            if(isQ(i,j)){
                unite(i,j);
            }
        }
        if(a[i].x<=a[i].s||n-a[i].y<=a[i].s){
            unite(0,i);
        }
        if(m-a[i].x<=a[i].s||a[i].y<=a[i].s){
            unite(k+1,i);
        }
    }
    if(same(0,k+1)){
        printf("N");
    }else printf("S");

    return 0;
}

