#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	scanf("%d",&x);
	int t=x%4;
	int ans;
	char ac;
	if(t==0) ans=1,ac='A';
	else if(t==1) ans=0,ac='A';
	else if(t==2) ans=1,ac='B';
	else if(t==3) ans=2,ac='A';
	printf("%d %c\n",ans,ac );
	return 0;
}