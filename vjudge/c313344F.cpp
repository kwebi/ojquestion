#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef pair<int,int> pii;

int a[100010];
pair<int,int> msum[100010];

int abs(int x) {
	return x<0?-x:x;
}

int main() {
	int n,k;
	while(true) {
		scanf("%d%d",&n,&k);
		if(n==k&&n==0)break;
		msum[0]=(pii){
			0,0
		};
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			msum[i]=(pii) {
				msum[i-1].first+a[i],i
			};
		}
		sort(msum,msum+1+n);
		for(int i=1; i<=k; i++) {
			int q;
			scanf("%d",&q);
			int l=0,r=1;
			int ql=0,qr=1;
			int qv;
			int tmp=1e9+7;
			while(l<=n&&r<=n) {
				int c=msum[r].first-msum[l].first;//c为正数，q也为正数
				if(abs(c-q)<tmp) {
					tmp=abs(c-q);
					ql=msum[l].second;
					qr=msum[r].second;
					qv=abs(c);
				}
				if(c>q)l++;
				else if(c<q)r++;
				else {
					break;
				}
				if(l==r)r++;
			}
			if(ql>qr)swap(ql,qr);
			printf("%d %d %d\n",qv,ql+1,qr);
		}
	}
	return 0;
}

