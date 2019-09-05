#include<bits/stdc++.h>
using namespace std;
#define update tr[t].su=tr[t<<1].su+tr[t<<1|1].su;if (tr[t].su>=M) tr[t].su-=M;
//每个子程序最后都要写这句，更新tr[t].su
typedef long long ll;
const int N=100003;
struct kk{
    ll mu,su,ad;
    //mu是维护乘积的懒惰标记，su是区间和，ad是加
    //要注意su和ad的区别
}tr[N<<2];//4倍空间
int n,M,i,a[N],op,x,y,m;
ll read(){
    ll x=0;
    char ch;
    do ch=getchar();while (ch<'0'||ch>'9');
    while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}
void build(int t,int l,int r){
    tr[t].mu=1;
    if (l==r){
        tr[t].su=a[l];
        return;
    }
    int mid=l+r>>1;
    build(t<<1,l,mid);
    build(t<<1|1,mid+1,r);
    update;
}
void maintain(int t,int k){//维护su,mu和ad
    tr[t<<1].su=(tr[t<<1].su*tr[t].mu+tr[t].ad*(k+1>>1))%M;
    tr[t<<1|1].su=(tr[t<<1|1].su*tr[t].mu+tr[t].ad*(k>>1))%M;
    tr[t<<1].mu=tr[t<<1].mu*tr[t].mu%M;
    tr[t<<1|1].mu=tr[t<<1|1].mu*tr[t].mu%M;
    tr[t<<1].ad=(tr[t<<1].ad*tr[t].mu+tr[t].ad)%M;
    tr[t<<1|1].ad=(tr[t<<1|1].ad*tr[t].mu+tr[t].ad)%M;
    tr[t].mu=1;tr[t].ad=0;
}
void cheng(int t,int l,int r,ll val){
    if (x<=l && r<=y){
        tr[t].mu=tr[t].mu*val%M;
        tr[t].ad=tr[t].ad*val%M;
        tr[t].su=tr[t].su*val%M;
        return;
    }
    maintain(t,r-l+1);
    int mid=l+r>>1;
    if (x<=mid) cheng(t<<1,l,mid,val);
    if (mid<y) cheng(t<<1|1,mid+1,r,val);
    update;
}
void jia(int t,int l,int r,ll val){
    if (x<=l && r<=y){
        tr[t].ad+=val;
        if (tr[t].ad>=M) tr[t].ad-=M;
        tr[t].su=(tr[t].su+(r-l+1)*val)%M;
        return;
    }
    maintain(t,r-l+1);
    int mid=l+r>>1;
    if (x<=mid) jia(t<<1,l,mid,val);
    if (mid<y) jia(t<<1|1,mid+1,r,val);
    update;
}
ll query(int t,int l,int r){
    if (x<=l && r<=y) return tr[t].su;
    maintain(t,r-l+1);
    int mid=l+r>>1;
    ll ans=0;
    if (x<=mid) ans+=query(t<<1,l,mid);
    if (mid<y) ans+=query(t<<1|1,mid+1,r);
    if (ans>=M) ans-=M;
    update;
    return ans;
}
int main(){
    n=read();M=read();
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    m=read();
    while (m--){
        op=read();x=read();y=read();
        if (op==1) cheng(1,1,n,read());
        if (op==2) jia(1,1,n,read());
        if (op==3) printf("%lld\n",query(1,1,n));
    }
}