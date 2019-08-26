#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[105];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		bool f=1;
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]>k){
				int t=(a[i+1]-a[i]-k);
				m-=t;
				if(m<0){
					f=0;break;
				}
			}else {
				int t=(k-(a[i+1]-a[i]));
				m+=t>a[i]?a[i]:t;
			}
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
