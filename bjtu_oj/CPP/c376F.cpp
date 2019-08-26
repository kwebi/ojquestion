#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=4e5+5;
int a[maxn];

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int t=(n-1)/k;
	int tmp=(n-1)%k;
	if(tmp>=2)tmp=2;
	printf("%d\n",2*t+tmp);
	for(int i=2;i<=k+1;i++) a[i]=1;
	for(int i=2;i<=n;i++) {
		printf("%d %d\n",a[i],i);
		a[i+k]=i;
	}
	return 0;
}

