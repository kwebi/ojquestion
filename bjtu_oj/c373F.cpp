#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define LC(x) (x<<1)
#define RC(x) (x<<1|1)

const int maxn=1e6+5;
int a[maxn];
int sgT[maxn<<2];
ll ans=0;
int n,k;

void pushup(int o){
	sgT[o]=sgT[LC(o)]^sgT[RC(o)];
}

void build(int o,int l,int r){
	if(l==r){
		sgT[o]=a[l];
	}
	int mid=(l+r)/2;
	build(LC(o),l,mid);
	build(RC(o),mid+1,r);
	pushup(o);
	if(sgT[o]>=k)ans++;
}

int main(){
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	return 0;
}
