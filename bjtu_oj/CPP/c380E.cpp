#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N=2e6+5;
int a[N];

int main(){
	int n;
	scanf("%d",&n);
	if(n&1){
		for(int i=1,t=1;i<=n/2;i++,t+=2){
			a[i]=t;
			a[n-i+1]=t;
		}
		a[(n/2)+1]=n;
		for(int i=n+1,t=2;i<=n+n/2;i++,t+=2){
			a[i]=t;
			a[3*n-i]=t;
		}
		a[2*n]=n;
	}else {
		for(int i=1,t=1;i<=n/2;i++,t+=2){
			a[i]=t;
			a[n-i+1]=t;
		}
		for(int i=n+1,t=2;i<=(n-1)/2+n;i++,t+=2){
			a[i]=t;
			a[3*n-i]=t;
		}
		a[2*n]=n;
		a[n+n/2]=n;
	}
	for(int i=1;i<=2*n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}


