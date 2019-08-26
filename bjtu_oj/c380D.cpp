#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;


int main() {
	int r,h;
	scanf("%d%d",&r,&h);
	int ans=h/r*2;
	h=h%r;
	if(h*2<r) {
		ans++;
	} else if(h*2<sqrt(3)*r) {
		ans+=2;
	} else {
		ans+=3;
	}
	printf("%d",ans);
	return 0;
}


