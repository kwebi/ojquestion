#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxn=1e5+5;
char s[maxn];
ull h[maxn];
ull k[maxn];
const ull seed=31;

ull getSub(int l,int r){
	return h[r]-h[l-1]*k[r-l+1];
}

int main(){
	k[0]=1;
	for(int i=1;i<maxn;i++){
		k[i]=k[i-1]*seed;
	}
	int m,l;
	while(~scanf("%d%d",&m,&l)){
		scanf("%s",s+1);
		int len=strlen(s+1);
		h[0]=0;
		for(int i=1;i<=len;i++){
			h[i]=h[i-1]*seed+s[i]-'a'+1;
		}
		int ans=0;
		
		for(int i=1;i<=l&&i+m*l<=len;i++){
			map<ull,int> mp;
			for(int j=i;j<i+m*l;j+=l){
				ull t=getSub(j,j+l-1);
				mp[t]++;
			}
			if(mp.size()==m){
				ans++;
			}
			for(int j=i+m*l;j+l-1<=len;j+=l){
				ull t1=getSub(j,j+l-1);
				ull t2=getSub(j-m*l,j-m*l+l-1);
				mp[t1]++;
				mp[t2]--;
				if(mp[t2]==0)mp.erase(t2);
				if(mp.size()==m)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

