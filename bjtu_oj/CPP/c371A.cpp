#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



int main(){
	int r,d;
	scanf("%d%d",&r,&d);
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		ll xi,yi,ri;
		scanf("%I64d%I64d%I64d",&xi,&yi,&ri);
		ll d1=(xi)*(xi)+yi*yi;
		if(d1>=(r-d+ri)*(r-d+ri)&&d1<=(r-ri)*(r-ri))cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
