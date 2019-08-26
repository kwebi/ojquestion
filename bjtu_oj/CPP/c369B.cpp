#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
	ll x1,y1;
	scanf("%I64d%I64d",&x1,&y1);
	ll x2,y2,n;
	scanf("%I64d%I64d%I64d",&x2,&y2,&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		double t1=a*x1+b*y1+c;
		double t2=a*x2+b*y2+c;
		if(t1*t2<0)ans++;
	}
	printf("%d",ans);
	return 0;
}
