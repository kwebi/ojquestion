#include<stdio.h>
#include<vector>
#include<queue>
#include<set>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=4e4+5;
const int INF=2e9+7;
int a[maxn];
struct N{
	int v;
	N(){
	}
	N(int _v):v(_v){
	}
	bool operator<(const N&b)const{
		return v>b.v;
	}
};
set<int> Set;
set<N> rSet;
typedef set<int>::iterator sit;
typedef set<N>::iterator snt;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	Set.insert(a[1]);
	rSet.insert(a[1]);
	ll ans=a[1];
	for(int i=2;i<=n;i++){
		sit it=Set.lower_bound(a[i]);
		snt rit=rSet.lower_bound(N(a[i]));
		
		int t=INF;
		if(it!=Set.end()){
			t=min(t,abs(*it-a[i]));
		}
		if(rit!=rSet.end()){
			int rv=(*rit).v;
			t=min(t,abs(rv-a[i]));
		}
		if(t==INF)t=0;
		//printf("t: %d\n",t);
		ans+=t;
		Set.insert(a[i]);
		rSet.insert(N(a[i]));
	}
	printf("%lld",ans);
	return 0;
}
