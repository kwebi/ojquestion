#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+5;
const int INF=1e9;
int a[maxn];
int p[maxn],g[maxn];
vector<pii> ans;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=2*n;i++)p[i]=g[i]=INF;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){
			p[++p[0]]=i;
		}else{
			g[++g[0]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		int now=0;
		int p1=0,g1=0;
		int c1=0,c2=0;
		bool f=1;
		while(now<=n){
			if(p[p1+i]==INF&&g[g1+i]==INF){
				f=0;break;
			}
			if(p[p1+i]<g[g1+i]){
				c1++;
				p1+=i;
				g1=p[p1]-p1;//g里有多少个球
				now=p[p1]+1;
			}else if(p[p1+i]>g[g1+i]){
				c2++;
				g1+=i;
				p1=g[g1]-g1;
				now=g[g1]+1;
			}
		}
		if(c1>c2&&a[n]!=1)f=0;
		if(c1<c2&&a[n]!=2)f=0;
		if(c1==c2)f=0;
		if(f){
			ans.push_back(make_pair(max(c1,c2),i));
		}
	}
	printf("%d\n",ans.size());
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	
	return 0;
}
