#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
int a[maxn];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int f=1;
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			f=i;break;
		}
	}
	if(f==1){
		printf("0");return 0;
	}else if(f==n){
		if(a[n]>a[1]){
			printf("-1");
		}else{
			printf("1");
		}
		return 0;
	}
	for(int i=f+1;i<=n;i++){
		if(a[i]<a[i-1]){
			printf("-1");return 0;
		}
	}
	if(a[n]>a[1]){
		printf("-1");return 0;
	}
	printf("%d",n-f+1);
	return 0;
}
