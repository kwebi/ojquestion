#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e4+5;
int a[maxn];
int vis[1010];
int main(){
	int k,n;
	scanf("%d%d",&k,&n);

	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]++;
	}
	vector<int> dif;
	map<int,int> mp;
	for(int i=1;i<=k;i++){
		mp[vis[i]]++;
	}
	if(mp.size()>3){
		printf("*");
	}else if(mp.size()==3){
		vector<pii> tmp;
		int cnt=0;
		for(auto e:mp){
			tmp.push_back(make_pair(e.first,e.second));
			if(e.second==1)cnt++;
		}
		sort(tmp.begin(),tmp.end());
		if(cnt<2){
			printf("*");return 0;
		}
		if(tmp[1].first-tmp[0].first==1&&tmp[0].second==1&&tmp[2].second==1&&tmp[2].first-tmp[1].first==1){
			int u,v;
			for(int i=1;i<=k;i++){
				if(vis[i]==tmp[0].first)u=i;
				if(vis[i]==tmp[2].first)v=i;
			}
			printf("-%d +%d",v,u);
		}else printf("*");
		
	}else if(mp.size()==2){
		vector<pii> tmp;
		int cnt=0;
		for(auto e:mp){
			tmp.push_back(make_pair(e.first,e.second));
			if(e.second==1)cnt++;
		}
		sort(tmp.begin(),tmp.end());
		if(cnt<1){
			printf("*");return 0;
		}
		if(tmp[1].first-tmp[0].first==1&&tmp[0].second==1){
			int u;
			for(int i=1;i<=k;i++){
				if(vis[i]==tmp[0].first)u=i;
			}
			printf("+%d",u);
		}else if(tmp[1].first-tmp[0].first==1&&tmp[1].second==1){
			int u;
			for(int i=1;i<=k;i++){
				if(vis[i]==tmp[1].first)u=i;
			}
			printf("-%d",u);
		}else
		printf("*");
	}
	return 0;
}
