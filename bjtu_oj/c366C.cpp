#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main() {
	int m,n;
	scanf("%d%d",&m,&n);
	double ans=0;
	double t=(1-pow((m-1)*1.0/m,n));
	ans+=m*t;
	for(int i=m-1; i>=2; i--) {
		double tmp=(1-pow((i-1)*1.0/m,n));
		ans+=i*(tmp-t);
		t=tmp;
	}
	if(m!=1)
		ans+=pow(1.0/m,n);
	printf("%.10lf",ans);
	return 0;
}
