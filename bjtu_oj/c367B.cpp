#include<bits/stdc++.h>
using namespace std;

#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+5;
int tree[maxn<<2];
int h,w,n;

void build(int o,int l,int r){
	if(l==r){
		tree[o]=w;
		return;
	}
	int mid=(l+r)/2;
	build(LC(o),l,mid);
	build(RC(o),mid+1,r);
	tree[o]=max(tree[LC(o)],tree[RC(o)]);
}

int query(int o,int l,int r,int w){
	if(l==r){
		//printf("treei: %d\n",tree[o]);
		tree[o]-=w;
		return l;
	}
	int mid=(l+r)/2;
	int ret;
	if(tree[LC(o)]>=w){
		ret = query(LC(o),l,mid,w);
	}else{
		ret = query(RC(o),mid+1,r,w);
	}
	tree[o]=max(tree[LC(o)],tree[RC(o)]);
	return ret;
}

int main(){
	while(~scanf("%d%d%d",&h,&w,&n)){
		h=min(h,n);
		build(1,1,h);
		for(int i=1;i<=n;i++){
			int wi;
			scanf("%d",&wi);
			if(tree[1]>=wi){
				printf("%d\n",query(1,1,h,wi));
			}else printf("-1\n");
		}
	}
	return 0;
}
