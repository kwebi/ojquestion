#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
int a[maxn];

int main() {
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		ll e=1ll<<60;
		ll b=0;
		while(b<e) {
			ll mid=(e+b)/2;
			if((mid/y+mid/x)>=a[i]) {
				e=mid;
			} else {
				b=mid+1;
			}
		}
		ll mid=e;
		if(mid%y==0&&mid%x==0)printf("Both\n");
		else if(mid%y==0) printf("Vanya\n");
		else if(mid%x==0)printf("Vova\n");
	}

	return 0;
}
