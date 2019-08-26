#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
int a[maxn];
struct Node {
	ll h,w;
	Node() {
	}
	Node(ll a,ll b):h(a),w(b) {
	}
};
Node Stk[maxn];

int main() {
	int n;
	while(~scanf("%d",&n)&&n!=0) {
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		a[n+1]=0;
		ll ans=0;
		int top=0;
		for(int i=1; i<=n+1; i++) {
			if(top==0) {
				Stk[top++]=Node(a[i],1);
			} else if(Stk[top-1].h>a[i]) {
				ll tw=0;
				while(top!=0&&Stk[top-1].h>a[i]){
					Stk[top-1].w+=tw;
					Node t=Stk[top-1];
					ans=max(ans,t.h*t.w);
					tw=t.w;
					top--;
				}
				Stk[top++]=Node(a[i],tw+1);
			}else{
				Stk[top++]=Node(a[i],1);
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
