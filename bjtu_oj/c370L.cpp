#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
typedef pair<int,int> pii;

const int a[]= {1,9,41,109,205,325,473,649,853,1085,1345};
i128 x[]= {10,11,12};
i128 y[]= {1345,1633,1949};

inline void out(i128 x) {
	if(x>9) out(x/10);
	putchar(x%10+'0');
}

int main() {
	int T;
	scanf("%d",&T);
	int cnt=0;
	while(T--) {
		int n;
		scanf("%d",&n);
		printf("Case #%d: ",++cnt);
		if(n<=10){
			printf("%d\n",a[n]);
			continue;
		}
		i128 ans=0;
		for(int i=0; i<3; i++) {
			i128 tmp=y[i];
			i128 t=1;
			for(int j=0; j<3; j++) {
				if(i==j)continue;
				tmp*=(n-x[j]);
				t*=(x[i]-x[j]);
			}
			ans+=tmp/t;
		}
		out(ans);
		printf("\n");
	}
	return 0;
}
