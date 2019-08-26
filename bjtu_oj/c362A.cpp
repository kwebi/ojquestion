#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=105;
int a[maxn];


int main() {
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int j=1; j<=n-1; j++) {
		int b=j,e=j+1;
		int t=0;
		if(a[b]==a[e]&&a[b]==x){
			b--;
			e++;
			t+=2;
			while(b>=1&&e<=n&&a[b]==a[e]){
				int l=0;
				int r=0;
				int tmp=a[e];
				while(b>=1){
					if(a[b]==tmp){
						l++;
						b--;
					}else{
						break;
					}
				}
				while(e<=n){
					if(a[e]==tmp){
						r++;
						e++;
					}else {
						break;
					}
				}
				//cout<<b<<endl;
				//cout<<e<<endl;
				if(l+r>=3){
					t+=l+r;
				}else{
					break;
				}
			}
		}
		
		ans=max(ans,t);
	}
	printf("%d\n",ans);
	return 0;
}
