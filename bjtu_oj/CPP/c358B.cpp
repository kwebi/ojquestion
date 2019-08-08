#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2e6+7;
int a[maxn];
int pre[maxn];
int ans[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int mx=-1e9;
	int mi=1e9;
	bool flag=0;
	for(int i=1;i<=n-1;i++){
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]+a[i];
		mx=max(mx,pre[i]);
		mi=min(mi,pre[i]);
	}
	if(flag||mi<-n+1||mx>n-1){
		printf("-1");
		return 0;
	}
	if(mi==-n+1){
		ans[1]=n;
	}else {
		ans[1]=n-mx;
	}
	map<int,int> mp;
	mp[ans[1]]=1;
	for(int i=1;i<=n-1;i++){
		ans[i+1] =pre[i]+ans[1];
		if(mp[ans[i+1]]){
			flag=1;
		}
		mp[ans[i+1]]=1;
	}
	for(int i=1;i<=n;i++){
		if(mp[i]==0){
			flag=1;
		}
	}
	if(flag){
		printf("-1");
	}else {
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
	}
	
	return 0;
}

