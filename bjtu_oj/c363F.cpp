#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;

struct Node{
	int c,d,id;
	bool operator<(const Node&o){
		return c==o.c?d<o.d:c<o.c;
	}
};
Node a[maxn];
Node b[maxn];
int ans[maxn];
int k[maxn];
set<pii> Set;

int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].c,&a[i].d);
		a[i].id=i;
	}
	scanf("%d",&m);
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&b[i].c,&b[i].d,&k[i]);
		b[i].id=i;
	}
	sort(b+1,b+1+m);
	for(int i=1,j=1;i<=n;i++){
		while(j<=m&&b[j].c<=a[i].c){
			Set.insert(make_pair(b[j].d,b[j].id));
			j++;
		}
		auto it=(Set.lower_bound(make_pair(a[i].d,0)));
		if(it==Set.end()||(*it).first<a[i].d){
			printf("NO\n");return 0;
		}else{
			ans[a[i].id]=(*it).second;
			k[(*it).second]--;
			if(k[(*it).second]==0){
				Set.erase(*it);
			}
		}
		
	}
	printf("YES\n");
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
