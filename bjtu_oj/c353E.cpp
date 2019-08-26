#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=350;

struct Node {
	int l,c;
};

bool cmp(const Node&x,const Node& y){
	return x.c<y.c;
}

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

Node a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].l);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].c);
	map<int,int> mp;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		for(auto &e:mp){
			int g=gcd(a[i].l,e.first);
			if(mp.count(g)==0){
				mp[g]=e.second+a[i].c;
			}else if(a[i].c+e.second<mp[g]) {
				mp[g]=a[i].c+e.second;
			}
		}
	}
	if(mp[1]==0)printf("-1\n");
	else printf("%d\n",mp[1]);
	return 0;
}
