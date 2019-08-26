#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+5;
const int M=maxn<<5;
int a[maxn];
int L[M],R[M],Sum[M],Hash[M];
int T[M];//根节点标号
int tot;

int build(int l,int r){//建立空树，记录左右结点
	int root=++tot;
	if(l!=r){
		int mid=(l+r)/2;
		L[root]=build(l,mid);
		R[root]=build(mid+1,r);
	}
	return root;
}

int update(int pre,int l,int r,int x){
	int num=++tot;
	L[num]=L[pre],R[num]=R[pre],Sum[num]=Sum[pre]+1;//拉一条链，并更新
	if(l!=r){
		int mid=(l+r)/2;
		if(x<=mid)L[num]=update(L[pre],l,mid,x);
		else R[num]=update(R[pre],mid+1,r,x);
	}
	return num;
}

int query(int u,int v,int l,int r,int k){
	if(l==r) return Hash[l];
	int mid=(l+r)/2;
	int num=Sum[L[v]]-Sum[L[u]];
	if(num>=k) return query(L[u],L[v],l,mid,k);
	else return query(R[u],R[v],mid+1,r,k-num);
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&Hash[i]);
		a[i]=Hash[i];
	}
	sort(Hash+1,Hash+n+1);
	int m=unique(Hash+1,Hash+n+1)-Hash-1;
	T[0] = build(1,m);
	for(int i=1;i<=n;i++){//建立主席树
		int x=lower_bound(Hash+1,Hash+m+1,a[i])-Hash;
		T[i]=update(T[i-1],1,m,x);
	}
	while(q--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(T[l-1],T[r],1,m,k));
	}
	return 0;
}
