#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxm=1e6+5;
pii a[maxm];
int ans[maxm];
map<pii,bool> mp;
map<pii,bool> vis;

ll exgcd(ll a,ll b,ll& x,ll& y) {
	if(b==0) {
		x=1;
		y=0;
		return a;
	}
	ll d=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return d;
}

int main() {
	ll n,m,dx,dy;
	cin>>n>>m>>dx>>dy;
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	ll x,y;
 	ll g = exgcd(n,-dx,x,y);

	for(int i=1; i<=m; i++) {//扩展欧几里得解线性方程:n*t-dx*k=a[i].first
		ll k=y*a[i].first/g;
		ll yi=(a[i].second+dy*k%n+n)%n;
		ans[yi]++;
	}
	int ay=0;
	int mx=0;
	for(int i=0; i<n; i++) {
		if(ans[i]>mx) {
			mx=ans[i];
			ay=i;
		}
	}
	printf("%d %d",0,ay);
	return 0;
}
