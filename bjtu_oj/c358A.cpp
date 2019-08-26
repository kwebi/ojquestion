#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2e6+7;
int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	int ans=0;
	int t=0;
	for(int i=1;i<=n*2;i++){
		if(a[i]==1){
			t++;
			ans=max(ans,t);
		}else {
			t=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
