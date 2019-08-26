#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int a[100];
int tmp[100]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=13;i<=24;i++){
		if(i==14)tmp[i]=tmp[i-12]-1;
		else tmp[i]=tmp[i-12];
	}
	for(int i=25;i<=36;i++){
		tmp[i]=tmp[i-12];
	}
	for(int i=37;i<=48;i++){
		tmp[i]=tmp[i-12];
	}
	for(int i=49;i<=96;i++){
		tmp[i]=tmp[i-48];
	}
	for(int i=13;i<=96;i++){
		bool f=1;
		int j,t;
		for(j=1,t=i;j<=n&&t<=96;j++,t++){
			if(tmp[t]!=a[j]){
				f=0;
				break;
			}
		}
		if(f&&(j==n+1)){
			printf("YES");return 0;
		}
	}
	printf("NO");
	return 0;
}


