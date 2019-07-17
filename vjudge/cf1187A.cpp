#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t1=0;t1<T;t1++){
		int n,s,t;
		scanf("%d%d%d",&n,&s,&t);
		printf("%d\n", n-min(s,t)+1);
	}
	return 0;
}