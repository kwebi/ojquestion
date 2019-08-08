#include<bits/stdc++.h>
using namespace std;

#define LF(i) (i<<1)
#define RT(i) (i<<1|1)

const int maxn=1e5+5;
int a[maxn];

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

struct Node {
	int mi,g,cnt;
	Node(){}
	Node(int _m,int _g,int _c):mi(_m),g(_g),cnt(_c){}
} segT[maxn<<2];

Node merge(const Node& a,const Node& b){
    int g=gcd(a.g,b.g);
    int cnt=0;
    if(a.mi<b.mi){
        if(a.mi==g) cnt=a.cnt;
        return Node(a.mi,g,cnt);
    }else if(a.mi>b.mi){
        if(b.mi==g) cnt=b.cnt;
        return Node(b.mi,g,cnt);
    }
    if(a.mi==g) cnt=a.cnt+b.cnt;
    return Node(a.mi,g,cnt);
}

void build(int i, int l,int r){
    if(l==r){
        segT[i]=Node(a[l],a[l],1);
        return;
    }
    int mid=(l+r)>>1;
    build(LF(i),l,mid);
    build(RT(i),mid+1,r);
    segT[i] = merge(segT[LF(i)],segT[RT(i)]);
}

Node query(int i,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr){
        return segT[i];
    }
    int mid=(l+r)>>1;
    if(qr<=mid) return query(LF(i),l,mid,ql,qr);
    else if(ql>mid) return query(RT(i),mid+1,r,ql,qr);
    return merge(query(LF(i),l,mid,ql,qr),query(RT(i),mid+1,r,ql,qr));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	build(1,1,n);
	int T;
	cin>>T;
	while(T--) {
		int l,r;
		cin>>l>>r;
        Node res=query(1,1,n,l,r);
        cout<<r-l+1-res.cnt<<endl;
	}

	return 0;
}

