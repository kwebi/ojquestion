#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+7;
int c[maxn];
int t[maxn];
vector<int> a,b;


int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
	}
	
	for(int i=2;i<=n;i++){
		a.push_back(c[i]-c[i-1]);
		b.push_back(t[i]-t[i-1]);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	bool flag=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			flag=1;break;
		}
	}
	if(c[0]!=t[0]||c[n]!=t[n]){
		flag=1;
	}
	if(flag){
		printf("No\n");
	}else {
		printf("Yes\n");
	}

	return 0;
}
