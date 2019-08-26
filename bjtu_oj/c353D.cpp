#include<bits/stdc++.h>

typedef long long ll;

const int maxn=5e5+5;
char s[maxn];
int a[maxn];
ll b[maxn];


bool check(char c){
	if(c=='I'||c=='E'||c=='O'||c=='A'||c=='U'||c=='Y')return 1;
	return 0;
}

int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	double ans=0;
	for(int i=1;i<=n;i++){
		if(check(s[i])){
			a[i]=1;
		}
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[n-i+1]-a[i-1];
		ans+=b[i]/(i*1.0);
	}
	printf("%.10lf\n",ans);
	
	return 0;
}

