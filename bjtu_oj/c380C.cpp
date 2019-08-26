#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int maxn=1e5+5;
struct Node {
	ll x,y;
	int id;
	bool operator<(const Node& b)const {
		return x==b.x?y<b.y:x<b.x;
	}
} a[maxn];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%I64d%I64d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	printf("%d %d ",a[1].id,a[2].id);
	ll t1=a[1].x-a[2].x;
	ll t2=a[1].y-a[2].y;
	ll g=__gcd(t1,t2);
	t1/=g,t2/=g;
	if(t1<0) {
		t1*=-1;
		t2*=-1;
	}
	pii p=make_pair(t1,t2);
	
	for(int i=3; i<=n; i++) {
		if(!(a[1].x==a[2].x&&a[i].x==a[1].x)) {
			if(a[1].y==a[2].y&&a[1].y==a[i].y)continue;
			ll t1=a[i].x-a[1].x;
			ll t2=a[i].y-a[1].y;
			ll g=__gcd(t1,t2);
			t1/=g,t2/=g;
			if(t1<0) {
				t1*=-1;
				t2*=-1;
			}
			pii p1=make_pair(t1,t2);
			if(p1==p)continue;
			printf("%d",a[i].id);
			return 0;
		}
	}
	return 0;
}


