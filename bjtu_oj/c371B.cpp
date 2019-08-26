#include<bits/stdc++.h>
#define eps (1e-7)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


struct Node {
	ll x,y;
};
Node a[10010];
bool vis[1007];
int n;

ll gcd(ll a,ll b) {
	return b==0?a:gcd(b,a%b);
}

double getK(Node a,Node b) {
	return (a.y-b.y)*1.0/(a.x-b.x);
}

bool check(double k,ll b) {
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(ll i=1; i<=n; i++) {
		if(a[i].y-b==1LL*(k*(i-1))) {
			vis[i]=1;
			cnt++;
		}
	}
	if(cnt==n)return false;
	if(cnt==n-1)return true;
	int p=0;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			p=i;
			break;
		}
	}
	for(int i=p+1; i<=n; i++) {
		if(!vis[i]&&fabs((double)(a[i].y-a[p].y)/(a[i].x-a[p].x)-k)>eps)return false;
	}
	return true;
}


int main() {
	scanf("%d",&n);
	for(ll i=1; i<=n; i++) {
		scanf("%I64d",&a[i].y);
		a[i].x=i;
	}
	bool ans=0;
	ans|=check(a[2].y-a[1].y,a[1].y);
	ans|=check(0.5*(a[3].y-a[1].y),a[1].y);
	ans|=check((a[3].y-a[2].y),2*a[2].y-a[3].y);
	if(ans)printf("YES\n");
	else printf("NO\n");
	return 0;
}

