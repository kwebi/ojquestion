#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=4e3;
struct Node{
	int x,y;
}a[maxn];
int tmp[maxn];
int cc[maxn];
bool cmp(Node a,Node b){
	return a.x==b.x?a.y>b.y:a.x<b.x;
}

int main(){
	int n,v;
	scanf("%d%d",&n,&v);
	int mx=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		cc[a[i].x]+=a[i].y;
		mx=max(mx,a[i].x);
	}
	int ans=0;
	for(int i=1;i<=mx+1;i++){
		int left=v;
		if(tmp[i]>v){
			ans+=v;
			tmp[i]-=v;
			left=0;
		}else {
			ans+=tmp[i];
			left-=tmp[i];
			tmp[i]=0;
		}
		if(cc[i]>left){
			ans+=left;
			tmp[i+1]+=cc[i]-left;
		}else {
			ans+=cc[i];
		}
	}
	printf("%d",ans);
	return 0;
}

//ios::sync_with_stdio(false);cin.tie(0);
