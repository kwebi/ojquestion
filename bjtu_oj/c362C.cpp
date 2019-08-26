#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e3+5;
char s[maxn];
int cc[maxn];
int n,p;

bool check(int pos,char c) {
	char p='0',pp='0';
	if(pos>1)p=s[pos-1];
	if(pos>2)pp=s[pos-2];
	if(c==p||c==pp)return false;
	return true;
}

int main() {
	scanf("%d%d",&n,&p);
	scanf("%s",s+1);
	char mx='a'+p-1;
	int p=n;
	int pre=n;
	while(p>=1&&p<=n) {
		char c=s[p];
		if(p<=pre) c++;
		else c='a';
		while(c<=mx&&!check(p,c))c++;
		if(c<=mx){
			s[p]=c;
			pre=p;
			p++;
		}else{
			pre=p;
			p--;
		}
	}
	if(p<1)printf("NO\n");
	else printf("%s\n",s+1);
	return 0;
}

