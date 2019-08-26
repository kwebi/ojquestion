#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
char s[maxn];
bool vis[maxn];

int main() {
	int n;
	scanf("%d",&n);
	scanf("%s",s);

	for(int i=0; i<n; i++) {
		if(s[i]=='L') {
			for(int i=0;i<10;i++){
				if(!vis[i]){
					vis[i]=1;
					break;
				}
			}
		} else if(s[i]=='R') {
			for(int i=9;i>=0;i--){
				if(!vis[i]){
					vis[i]=1;
					break;
				}
			}
		} else {
			int t=s[i]-'0';
			vis[t]=0;
		}
	}
	for(int i=0; i<10; i++)printf("%d",vis[i]);
	return 0;
}
