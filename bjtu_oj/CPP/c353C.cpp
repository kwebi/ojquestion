#include<bits/stdc++.h>
using namespace std;

int l[10];
int r[10];

int main() {
	int n;
	scanf("%d",&n);
	int _mi=1e9;
	int _mx=0;
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&l[i],&r[i]);
	}
	double ans=0;
	//for(int i=1;i<=10000;i++){
	for(int i=4;i<=4;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(l[j]>=i)cnt++;
		}
		if(cnt<2)continue;
		
	}
	printf("%.10lf\n",ans);

	return 0;
}

