#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

ll Mtx[10][10];



int main(){
    int T;
    scanf("%d",&T);
    Mtx[0][0]=1;
    Mtx[0][1]=1;
    Mtx[1][0]=1;
    while(T--){
    	int a,b,n;
    	scanf("%d%d%d",&a,&b,&n);
    	int t=n%3;
    	if(t==0)printf("%d\n",a);
    	else if(t==1)printf("%d\n",b);
    	else printf("%I64d\n",1LL*(a^b));
	}
	return 0;
}


