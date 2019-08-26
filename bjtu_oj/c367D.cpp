#include<stdio.h>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
const int maxn=2e5+5;
struct Node{
	int v,mi,mx;
	Node(){
	}
	Node(int a,int b,int c):v(a),mi(b),mx(c){
	}
}sgT[maxn<<2];
int a[maxn];

Node merge(const Node& a,const Node&b){
	return Node(0,min(a.mi,b.mi),max(a.mx,b.mx));
}

void pushup(int o){
	sgT[o].mi=min(sgT[LC(o)].mi,sgT[RC(o)].mi);
	sgT[o].mx=max(sgT[LC(o)].mx,sgT[RC(o)].mx);
}

void build(int o, int l,int r){
	if(l==r){
		sgT[o]=Node(a[l],a[l],a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(LC(o),l,mid);
	build(RC(o),mid+1,r);
	pushup(o);
}

Node query(int o,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr){
		return sgT[o];
	}
	int mid=(l+r)/2;
	if(mid>=qr)return query(LC(o),l,mid,ql,qr);
	else if(ql>mid) return query(RC(o),mid+1,r,ql,qr);
	return merge(query(LC(o),l,mid,ql,mid),query(RC(o),mid+1,r,mid+1,qr));
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		Node t=query(1,1,n,a,b);
		printf("%d\n",t.mx-t.mi);
	}
	return 0;
}
