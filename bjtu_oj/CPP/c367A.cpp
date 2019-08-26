#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=5e5+5;
struct Node{
	int v,p;
	bool operator<(const Node&b)const{
		return v<b.v;
	}
};

Node b[maxn];
int a[maxn];
int c[maxn];

int lowbit(int x){
	return x&(-x);
}

void update(int x,int y,int n){
	for(int i=x;i<=n;i+=lowbit(i)){
		c[i]+=y;
	}
}

int getSum(int x){
	int ret=0;
	for(int i=x;i;i-=lowbit(i)){
		ret+=c[i];
	}
	return ret;
}

int main(){
	int n;
	while(~scanf("%d",&n)&&n!=0){
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i].v);
			b[i].p=i;
		}
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++){
			a[b[i].p]=i;
			
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			update(a[i],1,n);
			ans+=i-getSum(a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
