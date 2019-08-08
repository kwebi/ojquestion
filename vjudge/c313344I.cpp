#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 5e4 + 5;
double mx[maxn];
double mw[maxn];
int n;

double getv(double x) {
	double ans=0;
	for(int i=1; i<=n; i++) {
		ans+=pow(abs(x-mx[i]),3)*mw[i];
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	int cnt=1;
	while (T--) {
		scanf("%d", &n);
		double mst=1e9+7;
		double mend=0;
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf", &mx[i], &mw[i]);
			mst=min(mst,mx[i]);
			mend=max(mend,mx[i]);
		}
		

		while(mend-mst>1e-7) {
			double mid=(mst+mend)/2;
			double rmid=(mid+mend)/2; 
			double lv=getv(mid);
			double rv=getv(rmid);
			if(lv<rv){
			    mend=rmid;
            }else {
                mst=mid;
            }
		}

		printf("Case #%d: %lld\n",cnt++,ll(getv(mst)+0.5));
	}
	return 0;
}
