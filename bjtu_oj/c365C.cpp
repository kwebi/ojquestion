#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
//适用于正负整数
template <class T>
inline bool scan_d(T &ret) {
	char c;
	int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}

inline void out(int x) {
	if(x>9) out(x/10);
	putchar(x%10+'0');
}

#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
const int maxn=2e5+5;
int a[maxn];
int LG;

struct Node {
	int w;
} sgT[maxn<<2];

int merge(int a,int b) {
	return min(a,b);
}

void build(int k,int l,int r) {
	if(l==r) {
		sgT[k].w=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(LC(k),l,mid);
	build(RC(k),mid+1,r);
	sgT[k].w=merge(sgT[LC(k)].w,sgT[RC(k)].w);
}

int query(int k,int l,int r,int ql,int qr) {
	if(l>=ql&&r<=qr) {
		return sgT[k].w;
	}
	int mid=(l+r)/2;
	if(qr<=mid)return query(LC(k),l,mid,ql,qr);
	else if(ql>mid)return query(RC(k),mid+1,r,ql,qr);
	return merge(query(LC(k),l,mid,ql,mid),query(RC(k),mid+1,r,mid+1,qr));
}

int dp[maxn][22];
int mm[maxn];
#define Pow2(x) (1<<x)

void initRMQ(int n,int b[]) {
	mm[0]=-1;
	for(int i=1; i<=n; i++) {
		mm[i]=(i&(i-1))==0?mm[i-1]+1:mm[i-1];
		dp[i][0]=b[i];
	}
	for(int j=1; j<=mm[n]; j++) {
		for(int i=1; i+-1<=n; i++) {
			dp[i][j]=min(dp[i][j-1],dp[i+Pow2((j-1))][j-1]);
		}
	}
}

int rmq(int x,int y) {
	int k=mm[y-x+1];
	return min(dp[x][k],dp[y-Pow2(k)+1][k]);
}

struct N {
	int v,l;
	N() {
	}
	N(int _v,int _l):v(_v),l(_l) {
	}
};
N Stk[maxn];
int ans[maxn];

int main() {
	int n;
	scan_d(n);
	int top=0;

	for(int i=1; i<=n; i++) {
		scan_d(a[i]);
	}
	for(int i=1; i<=n+1; i++) {
		if(top==0) {
			Stk[top++]=N(a[i],1);
		} else if(Stk[top-1].v>a[i]) {
			int tl=0;
			while(top!=0&&Stk[top-1].v>a[i]) {
				Stk[top-1].l+=tl;
				tl=Stk[top-1].l;
				ans[tl]=max(ans[tl],Stk[top-1].v);
				//printf("%d %d %d\n",i,tl,ans[tl]);
				top--;
			}
			Stk[top++]=N(a[i],tl+1);
		} else {
			Stk[top++]=N(a[i],1);
		}
	}
	for(int i=n-1;i>=1;i--){
		ans[i]=max(ans[i],ans[i+1]);
	}
	for(int i=1; i<=n; i++) {
		printf("%d ",ans[i]);
	}
	return 0;
}


