#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	int n;
	cin>>n;
	int t=1;
	int x=n/2;
	for(int i=x;i>=1;i--){
		for(int j=1;j<=i;j++){
			printf("*");
		}
		for(int j=1;j<=t;j++){
			printf("D");
		}t+=2;
		for(int j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	for(int i=1;i<=n;i++)printf("D");
	printf("\n");
	t=n-2;
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=i;j++){
			printf("*");
		}
		for(int j=1;j<=t;j++){
			printf("D");
		}
		t-=2;
		for(int j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
