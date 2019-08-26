#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

double e=1e-8;

int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	double t1=max(0.3*a,a-a/250.0*c);
	double t2=max(0.3*b,b-b/250.0*d);
	if(t1-t2>e)printf("Misha");
	else if(t2-t1>e) printf("Vasya");
	else printf("Tie");
	return 0;
}

