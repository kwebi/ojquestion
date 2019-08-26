#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
int a[maxn];
bool vis[maxn];
int main() {
	int q;
	scanf("%d",&q);
	while(q--) {
		int n;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		map<int,int> mp;
		vector<int> b;
		for(int i=1; i<=4*n; i++) {
			scanf("%d",&a[i]);
			mp[a[i]]++;
			if(mp[a[i]]==2) {
				b.push_back(a[i]);
				mp[a[i]]=0;
			}
		}
		bool tag=1;
		for(auto &e:mp){
			if(e.second!=0){
				tag=0;break;
			}
		}
		if(tag==0){
			printf("NO\n");continue;
		}
		vector<int> area;
		for(int i=1; i<b.size(); i++) {
			area.push_back(b[0]*b[i]);
		}
		bool f=0;
		
		for(int i=0; i<area.size(); i++) {
			int t=area[i];
			f=1;
			mp.clear();
			for(int i=0;i<b.size();i++){
				mp[b[i]]++;
			}
			for(int j=0; j<b.size(); j++) {
				if(t%b[j]==0&&mp[t/b[j]]!=0) {
					mp[t/b[j]]--;
				} else {
					f=0;
					break;
				}
			}
			if(f)break;
		}
		if(f)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
