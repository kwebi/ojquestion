#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=3e3+5;
int a[maxn];

typedef map<int,int>::iterator miter;

int main() {
	int n;
	while(~scanf("%d",&n)) {
		map<int,int> Hash;
		int tot=0;
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			Hash[a[i]]++;
			tot++;
		}
		int ans=0;
		while(tot) {
			for(miter it=Hash.begin();it!=Hash.end();){
				if(it->second>0){
					it->second-=1;
					tot--;
				}
				if(it->second==0){
					Hash.erase(it++);
				}else {
					it++;
				}
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}


