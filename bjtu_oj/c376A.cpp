#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
	ll n,x;
	scanf("%I64d%I64d",&n,&x);
	char s[5];
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		int d;
		scanf("%d",&d);
		if(s[0]=='+'){
			x+=d;
		}else {
			if(x<d)ans++;
			else x-=d;
		}
	}
	printf("%I64d %I64d",x,ans);
	return 0;
}

//ios::sync_with_stdio(false);cin.tie(0);
