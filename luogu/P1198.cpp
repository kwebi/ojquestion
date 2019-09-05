#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=2e5+1;
int Tr[(N<<2)+5];
const int INF=2e9+5;

void build(int o,int l,int r){
    if(l==r){
        Tr[o]=-INF;
        return;
    }
    int mid=(l+r)/2;
    build(LC(o),l,mid);
    build(RC(o),mid+1,r);
    Tr[o]=max(Tr[LC(o)],Tr[RC(o)]);
}

void update(int o,int k,int val,int l,int r){
    if(l==k&&r==k){
        Tr[o]=val;
        return;
    }
    int mid=(l+r)/2;
    if(k<=mid)update(LC(o),k,val,l,mid);
    else update(RC(o),k,val,mid+1,r);
    Tr[o]=max(Tr[LC(o)],Tr[RC(o)]);
}

int query(int o,int ql,int qr,int l,int r){
    if(ql==l&&qr==r){
        return Tr[o];
    }
    int mid=(l+r)/2;
    if(qr<=mid)return query(LC(o),ql,qr,l,mid);
    else if(ql>mid)return query(RC(o),ql,qr,mid+1,r);
    else return max(query(LC(o),ql,mid,l,mid),query(RC(o),mid+1,qr,mid+1,r));
}

int main(){
    int m,mod;
    scanf("%d%d",&m,&mod);
    char s[5];
    int b;
    int cnt=0;
    int t=0;
    for(int i=1;i<=m;i++){
        scanf("%s%d",s,&b);
        if(s[0]=='A'){
            ++cnt;
            update(1,cnt,(b+t)%mod,1,N);
        }else{
            int ans=query(1,cnt-b+1,cnt,1,N);
            t=ans;
            printf("%d\n",ans);
        }
    }
    return 0;
}

