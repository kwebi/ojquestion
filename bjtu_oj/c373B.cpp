#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,m;
ll ans=0;
vector<int> vn,vm;
int len1,len2;
bool vis[12];

void rdfs(bool limit,int dep) {
	if(dep==len2) {
		ans++;
		return;
	}
	int end=limit?vm[len2-dep-1]:6;
	for(int i=0; i<=end; i++) {
		if(vis[i])continue;
		vis[i]=1;
		rdfs(limit&&i==vm[len2-dep-1],dep+1);
		vis[i]=0;
	}
}

void dfs(bool limit,int dep) {
	if(dep==vn.size()) {
		rdfs(1,0);
		return;
	}
	int end=limit?vn[len1-dep-1]:6;
	for(int i=0; i<=end; i++) {
		if(vis[i])continue;
		vis[i]=1;
		dfs(limit&&i==vn[len1-dep-1],dep+1);
		vis[i]=0;
	}
}



int main() {
	scanf("%d%d",&n,&m);
	n--,m--;
	int t=n;
	while(t>0) {
		vn.push_back(t%7);
		t/=7;
	}
	if(vn.empty())vn.push_back(0);
	len1=vn.size();
	t=m;
	while(t>0) {
		vm.push_back(t%7);
		t/=7;
	}
	if(vm.empty())vm.push_back(0);
	len2=vm.size();

	dfs(1,0);
	printf("%d",ans);
	return 0;
}
