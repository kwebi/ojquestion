#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int p[10005];

int main() {
	int q;
	scanf("%d",&q);
	while(q--) {
		int n;
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		for(int i=1; i<=n; i++) {
			scanf("%d",&p[i+1000]);
		}
		int beg=1001;
		while(p[beg]!=1) {
			beg--;
			p[beg]=p[beg+n];
		}
		bool f=1;
		if(p[beg]==1) {
			int pre=1;
			for(int i=beg+1; i<beg+n; i++) {
				if(p[i]!=pre+1) {
					f=0;
					break;
				}
				pre++;
			}
		}
		if(f==0) {
			while(p[beg]!=n) {
				beg--;
				p[beg]=p[beg+n];
			}
		}
		f=1;
		if(p[beg]==n) {
			int pre=n;
			for(int i=beg+1; i<beg+n; i++) {
				if(p[i]!=pre-1) {
					f=0;
					break;
				}
				pre--;
			}
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
